#ifndef SPATIAL_HELPER
#define SPATIAL_HELPER

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

//define positions
#define ABSOLUTE 1
#define RELATIVE 2

typedef int position_type;
struct margins {
    GLfloat top;
    GLfloat bottom;
    GLfloat left;
    GLfloat right;
    GLfloat front;
    GLfloat back;
    margins(): top(0.03f),bottom(0.03f),left(0.03f),right(0.03f),front(0.03f),back(0.03f){}
};

struct dimensions {
    GLfloat width;
    GLfloat height;
    GLfloat depth;
    dimensions() : width(.03f), height(.01f), depth(.003f) {
    }
};
struct position {
    GLfloat x;
    GLfloat y;
    GLfloat z;
    position(): x(0.0f), y(0.0f), z(0.0f){}
};
struct Object3dProperties{
    glm::vec3 origin,destination,coords, color;
    glm::quat orientation;
    margins margin;
    position_type position;
    dimensions dimension;
    glm::vec3 scale;
    bool has_physics, visible,show_children ;
    Object3dProperties() : 
        color(glm::vec3(255,255,255)),
        position(ABSOLUTE), 
        has_physics(true),
        visible(true), 
        show_children(false),
        orientation(glm::normalize(glm::quat(glm::vec3(0.0f, 0.0f, 0.0f)))),
        destination(glm::vec3(0.0,0.0,0.0)),
        origin(glm::vec3(0.0,0.0,0.0)),
        scale(glm::vec3(0.03,0.01,0.003)),
        coords(glm::vec3(0.0,0.0,0.0))
    {}
};



#endif
