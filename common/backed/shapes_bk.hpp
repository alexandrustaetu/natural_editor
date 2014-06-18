
#ifndef SHAPES_HPP
#define SHAPES_HPP
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
class BoxShape{
public:
    bool drawn;
    glm::vec3 color;
    GLuint buffer;
    GLuint color_uniform;
    GLuint shader_program;
    glm::vec3 size;
    glm::vec3 position;
    void draw();
    BoxShape();
    BoxShape(glm::vec3,glm::vec3);
    BoxShape(float, float);
    void draw(GLuint, glm::mat4 *, glm::mat4 *);
};

#endif