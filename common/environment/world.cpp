#include "world.hpp"
#include <common/input/menu.hpp>
#include <common/controls.hpp>


double lastTime = glfwGetTime();
int nbFrames = 0;
void benchmark() {
    double currentTime = glfwGetTime();
    nbFrames++;
    if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1 sec ago
        printf("%f ms/frame\n", 1000.0 / double(nbFrames));
        std::cout << "\n";
        nbFrames = 0;
        lastTime += 1.0;
    }
}

void World::ScreenPosToWorldRay(
        //        int mouseX, int mouseY, // Mouse position, in pixels, from bottom-left corner of the window
        //        int screenWidth, int screenHeight, // Window size, in pixels
        //        glm::mat4 ViewMatrix, // Camera position and orientation
        //        glm::mat4 ProjectionMatrix, // Camera parameters (ratio, field of view, near and far planes)
        //        glm::vec3& out_origin, // Ouput : Origin of the ray. /!\ Starts at the near plane, so if you want the ray to start at the camera's position instead, ignore this.
        //        glm::vec3& out_direction // Ouput : Direction, in world space, of the ray that goes "through" the mouse.
        ) {

    //Normalized Device Coordinates start, end of ray
    float mouseX = this->view_width / 2;
    float mouseY = this->view_height / 2;
    glm::vec4 raystart_ndc = glm::vec4(
            ((float) mouseX / (float) this->view_width - 0.5f) * 2.0f,
            ((float) mouseY / (float) this->view_height - 0.5f) * 2.0f,
            -1.0, // The near plane maps to Z=-1 in Normalized Device Coordinates
            1.0f
            );
    glm::vec4 rayend_ndc = glm::vec4(
            ((float) mouseX / (float) this->view_width - 0.5f) * 2.0f,
            ((float) mouseY / (float) this->view_height - 0.5f) * 2.0f,
            0.0,
            1.0f
            );


    // The Projection matrix goes from Camera Space to NDC.
    // So inverse(ProjectionMatrix) goes from NDC to Camera Space.
    glm::mat4 InverseProjectionMatrix = glm::inverse(this->ProjectionMatrix);

    // The View Matrix goes from World Space to Camera Space.
    // So inverse(ViewMatrix) goes from Camera Space to World Space.
    glm::mat4 InverseViewMatrix = glm::inverse(this->ViewMatrix);

    glm::vec4 lRayStart_camera = InverseProjectionMatrix * raystart_ndc;
    lRayStart_camera /= lRayStart_camera.w;
    glm::vec4 lRayStart_world = InverseViewMatrix * lRayStart_camera;
    lRayStart_world /= lRayStart_world .w;
    glm::vec4 lRayEnd_camera = InverseProjectionMatrix * rayend_ndc;
    lRayEnd_camera /= lRayEnd_camera .w;
    glm::vec4 lRayEnd_world = InverseViewMatrix * lRayEnd_camera;
    lRayEnd_world /= lRayEnd_world .w;


    // Faster way (just one inverse)
    //glm::mat4 M = glm::inverse(ProjectionMatrix * ViewMatrix);
    //glm::vec4 lRayStart_world = M * lRayStart_NDC; lRayStart_world/=lRayStart_world.w;
    //glm::vec4 lRayEnd_world   = M * lRayEnd_NDC  ; lRayEnd_world  /=lRayEnd_world.w;


    glm::vec3 lRayDir_world(lRayEnd_world - lRayStart_world);
    lRayDir_world = glm::normalize(lRayDir_world);


    this->out_origin = glm::vec3(lRayStart_world);
    this->out_direction = glm::normalize(lRayDir_world);
}

void World::mouse() {
    this->ScreenPosToWorldRay();
    
    if (!this->leftmouse_recorded && glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) {
        this->clicked_position = this->out_origin;
        this->leftmouse_recorded = true;
    }

    if (this->leftmouse_recorded && !glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) {
        btCollisionWorld::ClosestRayResultCallback RayCallback(btVector3(this->out_origin.x, this->out_origin.y, this->out_origin.z), btVector3(this->out_direction.x, this->out_direction.y, this->out_direction.z));
        std::cout << this->out_direction.x << "|" << this->out_direction.y << "|" << this->out_direction.z << "|\n" ;
        std::cout << this->out_origin.x << "|" << this->out_origin.y << "|" << this->out_origin.z << "|\n" ;
        this->out_direction = this->out_direction * 1000.0f;
        this->physics->rayTest(btVector3(this->out_origin.x, this->out_origin.y, this->out_origin.z), btVector3(this->out_direction.x, this->out_direction.y, this->out_direction.z), RayCallback);

        SpatialObjectExpanded u_poi;
        if (RayCallback.hasHit()){
            u_poi = *static_cast<SpatialObjectExpanded*> (RayCallback.m_collisionObject->getUserPointer());
            std::cout << "||" << u_poi << "|| \n";
        };
        int time_from_last_click = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->mouse_r).count();

        if (this->out_origin == this->clicked_position) {
            if (time_from_last_click < 400) {
                std::cout << "-dclick" << std::endl;
                if (u_poi)u_poi->doubleclick();
                this->changed = true;
            } else {
                if (u_poi)u_poi->click();
                std::cout << "-click" << std::endl;
                this->changed = true;
            }
        }
        this->leftmouse_recorded = false;
        this->mouse_r = std::chrono::high_resolution_clock::now();
    }
    
    if (!this->rightmouse_recorded && glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT)) {
        this->clicked_position = this->out_origin;
        this->rightmouse_recorded = true;
    }
    
    if (this->rightmouse_recorded && !glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT)) {
        btCollisionWorld::ClosestRayResultCallback RayCallback(btVector3(this->out_origin.x, this->out_origin.y, this->out_origin.z), btVector3(this->out_direction.x, this->out_direction.y, this->out_direction.z));
        this->out_direction = this->out_direction * 1000.0f;
        this->physics->rayTest(btVector3(this->out_origin.x, this->out_origin.y, this->out_origin.z), btVector3(this->out_direction.x, this->out_direction.y, this->out_direction.z), RayCallback);

        SpatialObjectExpanded u_poi;
        if (RayCallback.hasHit()){
            u_poi = *static_cast<SpatialObjectExpanded*> (RayCallback.m_collisionObject->getUserPointer());
        } else {
            glm::vec3 p = glm::vec3(1,1,1);
            glm::vec3 pos = this->out_origin;
            pos.z -= 0.2;
            this->menu->create(&pos);
        }
        int time_from_last_click = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->mouse_r).count();

        if (this->out_origin == this->clicked_position) {
            if (time_from_last_click < 400) {
                if (u_poi)u_poi->doubleclick();
                this->changed = true;
            } else {
                if (u_poi)u_poi->rightclick();
                this->changed = true;
            }
        }
        this->rightmouse_recorded = false;
        this->mouse_r = std::chrono::high_resolution_clock::now();
    }
    
    
}

void World::update() {
    computeMatricesFromInputs();
    this->mouse();
    this->ProjectionMatrix = getProjectionMatrix();
    this->ViewMatrix = getViewMatrix();
    this->physicsdebug->SetMatrices(this->ViewMatrix, this->ProjectionMatrix);
    this->physics->stepSimulation(1 / 60, 7);
    this->physics->debugDrawWorld();
    benchmark();
}
void World::setMenu(Menu * menu){
    this->menu = menu;
}

World::World() : leftmouse_recorded(false), changed(false), view_width(1024), view_height(768) {
    this->mouse_r = std::chrono::high_resolution_clock::now();
    //initialize gl functions...
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
    }
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    if (!glfwOpenWindow(1024, 768, 0, 0, 0, 0, 32, 0, GLFW_WINDOW)) {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
    }

    // Initialize GLEW
    //glewExperimental = true; // Needed for core profile

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
    }
    glfwSetWindowTitle("Tutorial 06");

    // Ensure we can capture the escape key being pressed below
    glfwEnable(GLFW_STICKY_KEYS);
    glfwSetMousePos(1024 / 2, 768 / 2);

    // Dark blue background
    glClearColor(0.1f, 0.0f, 0.4f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);

    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);





    btBroadphaseInterface* broadphase = new btDbvtBroadphase();

    // Set up the collision configuration and dispatcher
    btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
    btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);

    // The actual physics solver
    btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;

    // The world.
    this->physics = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);

    btGhostPairCallback * ghostPairCallback = new btGhostPairCallback();
    this->physics->getPairCache()->setInternalGhostPairCallback(ghostPairCallback);

    this->physics->setGravity(btVector3(0, -9.81f, 0));
    NEGLDebugDrawer * physicsdebug = new NEGLDebugDrawer();
    this->physicsdebug = physicsdebug;
    this->physicsdebug->setDebugMode(btIDebugDraw::DBG_DrawWireframe); // so does this
    this->physics->setDebugDrawer(this->physicsdebug);

}

void World::place(SpatialObjectExpanded object) {
    //////////test if requested space is empty
    btCollisionShape* boxCollisionShape = new btBoxShape(btVector3(1.2, 1.2, 1.2));
    btPairCachingGhostObject* ghostObject = new btPairCachingGhostObject();
    btTransform trans;
    trans.setIdentity();
    trans.setOrigin(btVector3(1.2, 1.2, 1.2));
    ghostObject->setWorldTransform(trans);
    ghostObject->setCollisionShape(boxCollisionShape);
    ghostObject->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT | btCollisionObject::CF_NO_CONTACT_RESPONSE);

    this->physics->addCollisionObject(ghostObject, 1, 2);

    //                btManifoldArray manifoldArray;
    //                btBroadphasePairArray& pairArray = ghostObject->getOverlappingPairCache()->getOverlappingPairArray();
    while (ghostObject->getOverlappingPairCache()->getOverlappingPairArray().size() > 0) {
        //iterate over space positions, and see which slot is free
        this->physics->removeCollisionObject(ghostObject);
        trans.setOrigin(btVector3(1.2, 1.2, 1.2));
        ghostObject->setWorldTransform(trans);
        this->physics->addCollisionObject(ghostObject, 1, 2);
    }
    this->physics->removeCollisionObject(ghostObject);

    //this is to get the real colision, previous will get bounding box, i think.
    //                for (int i = 0; i < numPairs; i++) {
    //                    manifoldArray.clear();
    //
    //                    const btBroadphasePair& pair = pairArray[i];
    //
    //                    //unless we manually perform collision detection on this pair, the contacts are in the dynamics world paircache:
    //                    btBroadphasePair* collisionPair = dynamicsWorld->getPairCache()->findPair(pair.m_pProxy0, pair.m_pProxy1);
    //                    if (!collisionPair)
    //                        continue;
    //
    //                    if (collisionPair->m_algorithm)
    //                        collisionPair->m_algorithm->getAllContactManifolds(manifoldArray);
    //                    //cout << manifoldArray.size() << endl;
    //                    for (int j = 0; j < manifoldArray.size(); j++) {
    //                        btPersistentManifold* manifold = manifoldArray[j];
    //                        btScalar directionSign = manifold->getBody0() == ghostObject ? btScalar(-1.0) : btScalar(1.0);
    //                        for (int p = 0; p < manifold->getNumContacts(); p++) {
    //                            const btManifoldPoint&pt = manifold->getContactPoint(p);
    //                            if (pt.getDistance() < 0.f) {
    //                                const btVector3& ptA = pt.getPositionWorldOnA();
    //                                const btVector3& ptB = pt.getPositionWorldOnB();
    //                                const btVector3& normalOnB = pt.m_normalWorldOnB;
    //                                cout << "burned";
    //                                /// work here
    //                            }
    //                        }
    //                    }
    //                }

    ////////// end test if requested space is empty
}
