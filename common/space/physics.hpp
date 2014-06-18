#ifndef PHYSICS
#define PHYSICS

#include <common/space/helper.hpp>
#include <common/debug.hpp>

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