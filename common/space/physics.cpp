#include "physics.hpp"
#include <iostream>

Physics::Physics(Object3dProperties * props) {
    if (props->has_physics) {

        this->boxCollisionShape = new btBoxShape(btVector3(
                props->dimension.width * 1,
                props->dimension.height * 1,
                props->dimension.depth * 1
                ));

        btDefaultMotionState* motionstate = new btDefaultMotionState(btTransform(
                btQuaternion(props->orientation.x, props->orientation.y, props->orientation.z, props->orientation.w),
                btVector3(props->coords.x, props->coords.y, props->coords.z)
                ));
//        std::cout << std::endl << props->coords.x << props->coords.y << props->coords.z << std::endl;
//        std::cout << std::endl << props->dimension.width << props->dimension.height << props->dimension.depth;
        btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
                0, // mass, in kg. 0 -> Static object, will never move.
                motionstate,
                this->boxCollisionShape, // collision shape of body
                btVector3(0, 0, 0) // local inertia
                );
        this->rigidBody = new btRigidBody(rigidBodyCI);


    }
}
