#ifndef ENVIRONMENT
#define ENVIRONMENT



#include <common/space/physics.hpp>
#include <chrono>
#include <iostream>
#include <memory>
#include <common/space/object3d.hpp>
#include <common/controls.hpp>
// Include GLFW
#include <GL/glfw.h>
// Include GLEW
#include <GL/glew.h>
#include <common/input/menu.hpp>

class World
{
public:
    World();
    void place(SpatialObjectExpanded);
    void mouse();
    void setMenu(Menu *);
    void update();
    void ScreenPosToWorldRay();
    btDiscreteDynamicsWorld* physics;
    GLDebugDrawer * physicsdebug;
    glm::mat4 ProjectionMatrix,ViewMatrix;
    bool changed;
    Menu * menu;
private:
    glm::vec3 out_origin,out_direction,clicked_position;
    int view_width, view_height;
    std::chrono::high_resolution_clock::time_point mouse_r;
    bool leftmouse_recorded,rightmouse_recorded;
};

#endif