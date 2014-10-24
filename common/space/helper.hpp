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
    bool is_null;
    margins(){}
};

struct dimensions {
    GLfloat width;
    GLfloat height;
    GLfloat depth;
    bool is_null;
    dimensions(){}
};
struct position {
    GLfloat x;
    GLfloat y;
    GLfloat z;
    bool is_null;
    position(){}
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
        orientation(glm::normalize(glm::quat(glm::vec3(0.0f, 0.0f, 0.0f))))
    {}
};



#endif
