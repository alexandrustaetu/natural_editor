#ifndef CANVAS
#define CANVAS
#include <vector>
#include <common/handle.hpp>
#include <common/space/object3d.hpp>
#include <memory>
#include <iostream>
#include <common/space/scene.hpp>

class Canvas3dProperties :
public Object3dProperties {
public:

    Canvas3dProperties() {
        this->color = glm::vec3(111, 111, 111);
        this->dimension.width = 0.5;
        this->dimension.height = 1;
        this->dimension.depth = 0.001;
    };

};

class Canvas  : 
public Object3d<Canvas>
{
public:

    Canvas(): name(""), Object3d(new Canvas3dProperties) {};
    
    std::shared_ptr<Canvas> handle;
    bool active;
    std::string name;
    std::vector<std::shared_ptr<Canvas> > children;
    std::shared_ptr<Canvas> parent;
    void update();
    void open(std::string);
    void click(){
        std::cout << "Canvas clicked" << std::endl;
    };
    void doubleclick(){
    1;
    };

};

#endif