#include <common/space/grid.hpp>
#include <iostream>
Grid::Grid(){
    this->shader = LoadShaders("box.vertexshader", "box.fragmentshader");

    //x direction
    //Real size of the line spacing is .1 . The points will be declared from +1 to -1, so the total width is 2. This system works with bullet too.We will increment by .2 in order to have real .1 sizes
    for(float i = -2; i < 2.1; i+=.2){

        this->points.push_back(glm::vec3(i,-10,0));
        this->points.push_back(glm::vec3(i,10,0));
        this->points.push_back( glm::vec3(i,0,-10));
        this->points.push_back( glm::vec3(i,0,10));

        this->points.push_back(glm::vec3(-10,i,0));
        this->points.push_back(glm::vec3(10,i,0));
        this->points.push_back( glm::vec3(0,i,-10));
        this->points.push_back( glm::vec3(0,i,10));

        this->points.push_back(glm::vec3(-10,0,i));
        this->points.push_back(glm::vec3(10,0,i));
        this->points.push_back( glm::vec3(0,-10,i));
        this->points.push_back( glm::vec3(0,10,i));
    };

    glGenBuffers(1, &this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->points.size(), this->points.data(), GL_STATIC_DRAW);

};
void Grid::draw(glm::mat4 * mvp){
    glUseProgram(this->shader);
    GLuint mvp_uniform = glGetUniformLocation(this->shader, "MVP");

    glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

    glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, glm::value_ptr(*mvp) );

    glDrawArrays(GL_LINES, 0, this->points.size() );
    glDisableVertexAttribArray(0);
};


