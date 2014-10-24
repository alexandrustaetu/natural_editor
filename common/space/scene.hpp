#ifndef SCENE
#define SCENE
// Include GLEW
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <common/space/object3d.hpp>
#include <vector>
#include <memory>
#include <common/shader.hpp>
#include <common/space/helper.hpp>

class Scene {
public:

    Scene();
};

class ArraysInstanced {
public:
    ArraysInstanced();
    void setUp(std::vector<GLfloat> * pattern);
    //    void AddElement(SpatialObjectExpanded) {};

    template <class T>
    void addBorders(T object) {

/*       7_____________________3
         *\                    *\ 
         | \                   | \
         |  \ _________________|__\ 
         |  8*                 |   *4
         |___|_________________|   |
        6*   |                 *2  |
          \  |                  \  |
           \ |                   \ |
            \*____________________\* 
            5                      1
 *         Pass all the points in pairs of two. Draw these coordonates with gllines from an array    
 *          
 *          pairs will be: 1:5 ; 1:2 ; 1:4 ; 2:6 ; 2:3 ; 3:7 ; 3:4 ; 4:8 ; 5:6 ; 5:8 ; 6:7 ; 7:8
 * 
 *          Will receive the dimensions and the coords:
 * 
        */        
        
        //coords
        GLfloat x = object->coords.x;
        GLfloat y = object->coords.y;
        GLfloat z = object->coords.z;

        //width; height; depth Because the object is from -1 to +1, we will not divide by two. If we halve the dimensions,
        // the borders will be half of the displayed object. Bullet is working with -1 -> +1
        GLfloat half_width = object->dimension.width;
        GLfloat half_height = object->dimension.height;
        GLfloat half_depth = object->dimension.depth;
        
        glm::vec3 P1 = glm::vec3(x+half_width,y-half_height,z+half_depth);
        glm::vec3 P2 = glm::vec3(x+half_width,y-half_height,z-half_depth);
        glm::vec3 P3 = glm::vec3(x+half_width,y+half_height,z-half_depth);
        glm::vec3 P4 = glm::vec3(x+half_width,y+half_height,z+half_depth);

        glm::vec3 P5 = glm::vec3(x-half_width,y-half_height,z+half_depth);
        glm::vec3 P6 = glm::vec3(x-half_width,y-half_height,z-half_depth);
        glm::vec3 P7 = glm::vec3(x-half_width,y+half_height,z-half_depth);
        glm::vec3 P8 = glm::vec3(x-half_width,y+half_height,z+half_depth);
        
        //1:5
        this->borders.push_back(P1);this->borders.push_back(P5);
        //1:2
        this->borders.push_back(P1);this->borders.push_back(P2);
        //1:4
        this->borders.push_back(P1);this->borders.push_back(P4);
        //2:6
        this->borders.push_back(P2);this->borders.push_back(P6);
        //2:3
        this->borders.push_back(P2);this->borders.push_back(P3);
        //3:7
        this->borders.push_back(P3);this->borders.push_back(P7);
        //3:4
        this->borders.push_back(P3);this->borders.push_back(P4);
        //4:8
        this->borders.push_back(P4);this->borders.push_back(P8);
        //5:6
        this->borders.push_back(P5);this->borders.push_back(P6);
        //5:8
        this->borders.push_back(P5);this->borders.push_back(P8);
        //6:7
        this->borders.push_back(P6);this->borders.push_back(P7);
        //7:8
        this->borders.push_back(P7);this->borders.push_back(P8);
        
        //To extract the corners border/edges from the vector, get
        // 12 entries from the scene index of the element. For ex:
        // We want to rewrite a previous element data for update/memory
        // management : if it is the 3rd element, it will have index 2. before
        // it, there are already 2 elements, with 12 indices. so there are
        // 24 edges before. We will take the indice starring from 24 included
        // up to 35 in the vector. The general formula is,
        // (scene index - 1) * 2 , with 12 elements alocated
    }
    

    template <class T>
    void place(T object) {
        if (object->parent) {

            int enclosing_width, enclosing_height, side_length;
            side_length = enclosing_width = enclosing_height = ceil(sqrt(object->siblings_count));

            if (side_length > 10) {
                enclosing_width = enclosing_height = side_length = 10;
            } else if (side_length < 5) {
                side_length = object->siblings_count;
                enclosing_height = 1;
            }


            int position_y = floor(object->order / enclosing_width) + 1;
            int position_x = object->order % enclosing_width + 1;
            GLfloat real_enclosing_width = enclosing_width * (object->dimension.width + object->margin.left + object->margin.right) - object->margin.right;
            GLfloat real_enclosing_height = enclosing_height * (object->dimension.height + object->margin.top + object->margin.bottom) - object->margin.bottom;

            GLfloat real_position_x = position_x * (object->dimension.width + object->margin.left + object->margin.right) - (object->margin.right + object->margin.left);
            GLfloat real_position_y = position_y * (object->dimension.height + object->margin.top + object->margin.bottom) - (object->margin.bottom + object->margin.top);

            glm::vec3 parent_coords = object->parent->coords;
            margins parent_margins = object->parent->margin;
            dimensions parent_dimensions = object->parent->dimension;

            object->origin = object->parent->coords;

            object->destination.z = parent_coords.z -
                    parent_margins.back -
                    parent_dimensions.depth
                    ;
            object->destination.x = real_position_x;
            object->destination.y = real_position_y;

            object->coords = object->destination;

        }

        //////////test if requested space is empty
        //    btCollisionShape* boxCollisionShape = new btBoxShape(btVector3(1.2, 1.2, 1.2));
        //    btPairCachingGhostObject* ghostObject = new btPairCachingGhostObject();
        //    btTransform trans;
        //    trans.setIdentity();
        //    trans.setOrigin(btVector3(1.2, 1.2, 1.2));
        //    ghostObject->setWorldTransform(trans);
        //    ghostObject->setCollisionShape(boxCollisionShape);
        //    ghostObject->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT | btCollisionObject::CF_NO_CONTACT_RESPONSE);
        //
        //    this->physics->addCollisionObject(ghostObject, 1, 2);
        //
        //    //                btManifoldArray manifoldArray;
        //    //                btBroadphasePairArray& pairArray = ghostObject->getOverlappingPairCache()->getOverlappingPairArray();
        //    while (ghostObject->getOverlappingPairCache()->getOverlappingPairArray().size() > 0) {
        //        //iterate over space positions, and see which slot is free
        //        this->physics->removeCollisionObject(ghostObject);
        //        trans.setOrigin(btVector3(1.2, 1.2, 1.2));
        //        ghostObject->setWorldTransform(trans);
        //        this->physics->addCollisionObject(ghostObject, 1, 2);
        //    }
        //    this->physics->removeCollisionObject(ghostObject);

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

    template <class T >
    void AddElement(T element) {

        element->handle = element->shared_from_this();

        place(element);
//        std::cout << "[void AddElement][common/space/scene.hpp] element coords x" << element->coords.x << std::endl;
        positions.push_back(element->coords);
        element->sceneIndex = positions.size() - 1;
        /*this->scales.push_back(glm::vec3(
                element->dimension.width,
                element->dimension.height,
                element->dimension.depth
                ));*/
        scales.push_back(element->scale);
        colors.push_back(element->color);
        if (element->physics) {
            element->physics->rigidBody->translate(btVector3(element->coords.x, element->coords.y, element->coords.z));
            btTransform pos = element->physics->rigidBody->getWorldTransform();
            element->physics->rigidBody->activate(true);
            this->physics->addRigidBody(element->physics->rigidBody);

            element->physics->rigidBody->setUserPointer(&element->handle);
        }

        addBorders(element);
        
        changed = true;
    }
    void draw(glm::mat4 *);
    void updateSceneData();
    void drawBorders(glm::mat4 *);
    //    void setPhysics(btDiscreteDynamicsWorld*);
    //void place(SpatialObjectExpanded);
    //    void changeElement(SpatialObjectExpanded);

    template <class T>
    void changeElement(T element) {
//        std::cout << "[void changeElement][common/space/scene.hpp] element index: " << element->sceneIndex << std::endl;
//        std::cout << "[void changeElement][common/space/scene.hpp] positions size: " << this->positions.size() << std::endl;
        this->positions[element->sceneIndex] = element->coords;
        //this->scales[element->sceneIndex] = glm::vec3(
          //      element->dimension.width,
            //    element->dimension.height,
              //  element->dimension.depth
                //);
        this->scales[element->sceneIndex] = element->scale;
        this->colors[element->sceneIndex] = element->color;
        this->changed = true;
    }
    bool changed;
private:
    GLuint vao;
    btDiscreteDynamicsWorld* physics;
    GLuint shader,borders_shader;
    int points_count;
    GLuint borders_mvp_uniform, mvp_uniform, position_uniform, scale_uniform, color_uniform,indices_uniform, borders_uniform;
    GLuint indices_buffer, positions_buffer, colors_buffer, scales_buffer, borders_buffer;
    std::vector<glm::vec3> positions, colors, scales;
    
    //will pass to the videocard the points in pairs(each point with x and y),
    // for each line of the delimiting cube/paralelipiped
    std::vector<glm::vec3> borders;

};

#endif
