#include <common/text/text.hpp>

#include <iostream>


#include <common/environment/world.hpp>
extern World * world;

TextRenderer::TextRenderer() {
    this->physics = world->physics;
    Object3dProperties props;
    props.has_physics = false;
    for (int i = 0; i < 127; i++) {
        this->letters.push_back(new Letter(static_cast<char> (i)));
    }
    std::cout << this->letters.size();

}

void TextRenderer::addString(std::string * string){
    for(char& c : *string) {
        std::cout << c << std::endl;
    }
    
}

void TextRenderer::draw(glm::mat4 * mvp){
    for(Letter * letter : this->letters) {
        letter->scene.draw(mvp);
    }
}


void TextRenderer::label(SpatialObjectExpanded object,std::string name){
    
    GLfloat width = 0.0;
    
    Object3dProperties props;
    props.position = RELATIVE;
    props.dimension.width = 0;
    props.dimension.height = 0.01;
    props.color = glm::vec3(0,0,111);
//    this->name = name;
    
    for(char& c : name) {
       width += this->letters[static_cast<int> (c)]->width;
    }
    std::cout << width << std::endl;
//    this->spatial_construct = std::make_shared<Object3d>(&props);
}
