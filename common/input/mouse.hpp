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
class Mouse
{
public:
    Mouse(){};
    Mouse(btDiscreteDynamicsWorld*,int,int);
    int view_width,view_height;
    void ScreenPosToWorldRay();
    btDiscreteDynamicsWorld* physics
    void action();
    
private:
    glm::vec3 out_origin,out_direction,clicked_position;
    
    std::chrono::high_resolution_clock::time_point mouse_clicked,mouse_released;
    bool mouse_recorded;
};

#endif