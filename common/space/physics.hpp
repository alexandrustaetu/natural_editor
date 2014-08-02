#ifndef PHYSICS
#define PHYSICS

#include <common/space/helper.hpp>

#include <LinearMath/btIDebugDraw.h>
#include <btBulletDynamicsCommon.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

class Physics
{
public:
    Physics(){};
    Physics(Object3dProperties *);
    btRigidBody *rigidBody;
private:
    btCollisionShape* boxCollisionShape;
};

#endif