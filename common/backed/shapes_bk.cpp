#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shapes_bk.hpp"
#include <common/shader_utils.hpp>
using namespace std;
static const GLfloat cube_vertex_data[] = {
    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f
};

BoxShape::BoxShape() {
}
BoxShape::BoxShape(glm::vec3 position, glm::vec3 size):drawn(false) {
    this->position = position;
    this->size = size;
    
}

void BoxShape::draw(GLuint mvp_uniform, glm::mat4 * projection, glm::mat4 * view) {
    GLuint shapebuffer;
    glGenBuffers(1, &shapebuffer);
    glBindBuffer(GL_ARRAY_BUFFER, shapebuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof (cube_vertex_data), cube_vertex_data, GL_STATIC_DRAW);
    this->buffer = shapebuffer;
    //cube2
    glEnableVertexAttribArray(0);
        glVertexAttribPointer(
        0, // attribute. No particular reason for 0, but must match the layout in the shader.
        3, // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0, // stride
        (void*) 0 // array buffer offset
        );
    glUseProgram(this->shader_program); //color
    glm::mat4 ModelMatrix = glm::scale(glm::translate(glm::mat4(), this->position), this->size); // A bit to the left
    glm::mat4 MVP =  * projection * * view * ModelMatrix;
    glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, &MVP[0][0]);
    glUniform3fv(this->color_uniform, 1, &this->color[0]);
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
    glDrawArrays(GL_TRIANGLES, 0, 12 * 3); // 12*3 indices starting at 0 -> 12 triangles
    glDisableVertexAttribArray(0);
}