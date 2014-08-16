#ifndef GRID
#define GRID

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <common/shader.hpp>

class Grid
{
public:

    Grid();
    int shader;
    GLuint buffer;

    std::vector<glm::vec3> points;

    void draw(glm::mat4 *);
    };

#endif
