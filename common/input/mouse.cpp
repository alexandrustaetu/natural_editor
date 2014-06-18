#include "mouse.hpp"

void Mouse::ScreenPosToWorldRay(
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

void Mouse::action() {
    this->ScreenPosToWorldRay();
    if (!this->mouse_recorded && glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) {
        this->clicked_position = this->out_origin;
        this->mouse_recorded = true;
    }

    if (this->mouse_recorded && !glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) {
        this->mouse_released = std::chrono::high_resolution_clock::now();
        this->mouse_recorded = false;
        if (this->out_origin == this->clicked_position) {
            if (std::chrono::duration_cast<std::chrono::milliseconds>(this->mouse_released - this->mouse_clicked).count() < 400) {
                std::cout << "we have doubleclick\n";
            }
            this->mouse_clicked = std::chrono::high_resolution_clock::now();
        }

        this->out_direction = this->out_direction * 1000.0f;
        btCollisionWorld::ClosestRayResultCallback RayCallback(btVector3(this->out_origin.x, this->out_origin.y, this->out_origin.z), btVector3(this->out_direction.x, this->out_direction.y, this->out_direction.z));
        this->physics->rayTest(btVector3(this->out_origin.x, this->out_origin.y, this->out_origin.z), btVector3(this->out_direction.x, this->out_direction.y, this->out_direction.z), RayCallback);
        if (RayCallback.hasHit()) {
            std::cout << "badunga";
            std::shared_ptr<Object3d> u_poi = *static_cast<std::shared_ptr<Object3d>*> (RayCallback.m_collisionObject->getUserPointer());
            //std::cout << u_poi->has_physics << std::endl;

        }


    }
}

Mouse::Mouse(btDiscreteDynamicsWorld* physics,int view_width,int view_height) : mouse_recorded(false) {
this->physics = physics;    
this->view_width = view_width;
this->view_height = view_height;
}

void World::testspace() {
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
