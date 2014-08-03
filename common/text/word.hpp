#ifndef WORD
#define WORD
#include <vector>
#include <common/handle.hpp>
#include <common/space/object3d.hpp>
#include <memory>
#include <iostream>
#include <common/space/scene.hpp>
#include <common/text/canvas.hpp>

class Word  : 
//public Object3dExpanded
public Object3d<Word>
{
public:

    Word(): name(""), Object3d(new Object3dProperties) {};
    Word(bool);
    
    ArraysInstanced * scene;
    std::shared_ptr<Word> handle;
    bool active;
    std::string name;
    std::vector<std::shared_ptr<Word> > children;
    std::shared_ptr<Canvas> parent;
    void update();
    void open(std::string);
    void click(){
        std::cout << "word clicked" << std::endl;
    };
    void doubleclick(){
    1;
    };

};

#endif