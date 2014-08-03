#ifndef SCENE
#define SCENE
// Include GLEW
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "object3d.hpp"
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
    void SetIndices(std::vector<GLfloat> * pattern);
    //    void AddElement(SpatialObjectExpanded) {};

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

        this->place(element);
        std::cout << "[void AddElement][common/space/scene.hpp] element coords x" << element->coords.x << std::endl;
        this->positions.push_back(element->coords);
        element->sceneIndex = this->positions.size() - 1;
        this->scales.push_back(glm::vec3(
                element->dimension.width,
                element->dimension.height,
                element->dimension.depth
                ));

        this->colors.push_back(element->color);
        if (element->physics) {
            element->physics->rigidBody->translate(btVector3(element->coords.x, element->coords.y, element->coords.z));
            btTransform pos = element->physics->rigidBody->getWorldTransform();
            element->physics->rigidBody->activate(true);
            this->physics->addRigidBody(element->physics->rigidBody);

            element->physics->rigidBody->setUserPointer(&element->handle);
        }

        this->changed = true;
    }
    void draw(glm::mat4 *);
    //    void setPhysics(btDiscreteDynamicsWorld*);
    void place(SpatialObjectExpanded);
    //    void changeElement(SpatialObjectExpanded);

    template <class T>
    void changeElement(T element) {
        std::cout << "[void changeElement][common/space/scene.hpp] element index: " << element->sceneIndex << std::endl;
        std::cout << "[void changeElement][common/space/scene.hpp] positions size: " << this->positions.size() << std::endl;
        this->positions[element->sceneIndex] = element->coords;
        this->scales[element->sceneIndex] = glm::vec3(
                element->dimension.width,
                element->dimension.height,
                element->dimension.depth
                );
        this->colors[element->sceneIndex] = element->color;
        this->changed = true;
    }
    bool changed;
private:
    GLuint vao;
    btDiscreteDynamicsWorld* physics;
    GLuint shader;
    int points_count;
    GLuint mvp_uniform, position_uniform, scale_uniform, color_uniform;
    GLuint indices_buffer, positions_buffer, colors_buffer, scales_buffer;
    std::vector<glm::vec3> positions, colors, scales;

};

#endif