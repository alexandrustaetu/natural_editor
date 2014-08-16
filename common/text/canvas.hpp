#ifndef CANVAS
#define CANVAS
#include <vector>
#include <common/handle.hpp>
#include <common/space/object3d.hpp>
#include <memory>
#include <iostream>
#include <common/space/scene.hpp>
//#include <common/text/word.hpp>
class Canvas3dProperties :
public Object3dProperties {
public:

    Canvas3dProperties() {
        this->color = glm::vec3(111, 111, 111);
        this->dimension.width = 0.5;
        this->dimension.height = 1;
        this->dimension.depth = 0.001;
        this->coords.x = -1;
        this->coords.y = -1;
        this->coords.z = -1;
        this->scale = glm::vec3(0.5,1,0.001);
    };

};

class Canvas  : 
public Object3d<Canvas>
{
public:

    Canvas(): name(""), Object3d(new Canvas3dProperties) {};
    
    std::shared_ptr<Canvas> handle;
    bool active;
    GLfloat cursor_width;
    GLfloat cursor_height;
    
    std::string name;
    std::vector<std::shared_ptr<Canvas> > children;
    std::shared_ptr<Canvas> parent;
    void update();
    void open(std::string);
    
    template <class T2>
    void place(std::shared_ptr<T2> word){
        if(word->next_line){
            this->cursor_width = 0;
            this->cursor_height -= word->dimension.height;
        }
        
        word->coords.x = this->coords.x + this->cursor_width;
        word->coords.y = this->coords.y + this->cursor_height;
        
        cursor_width += word->dimension.width;
//        std::cout << word->dimension.width << "aaa" << std::endl;
//        exit(0);
    };
    void click(){
        std::cout << "Canvas clicked" << std::endl;
    };
    void doubleclick(){
    1;
    };

};

#endif
