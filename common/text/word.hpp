#ifndef WORD
#define WORD
#include <vector>
#include <common/handle.hpp>
#include <common/space/object3d.hpp>
#include <memory>
#include <iostream>
#include <common/space/scene.hpp>
#include <common/text/canvas.hpp>

class Word3dProperties : public Object3dProperties {
    public:
        Word3dProperties(){
            this->position = RELATIVE;
        };
        std::shared_ptr<Canvas> parent;
};

class Word  : 
//public Object3dExpanded
public Object3d<Word>
{
public:

    Word(Word3dProperties * props): name(""), Object3d(props) {
        if(!props->parent){
            std::cout << "[Word(Word3dProperties * props): name(""), Object3d(props)][common/text/word.hpp] a valid text canvas has to be specified";
            exit(0);
        }
        
        
        
        this->parent = props->parent;
        
        
    };
    Word(): name(""), Object3d(new Word3dProperties) {};
//    Word(bool);
    
    ArraysInstanced * scene;
    std::shared_ptr<Word> handle;
    bool active;
    bool next_line;
    std::string name;
    std::vector<std::shared_ptr<Word> > children;
    std::shared_ptr<Canvas> parent;
    void update(){
//         std::cout << "{" << this->dimension.width << "}" << std::endl;exit(0);
         this->parent->place(this->handle);
        std::cout << "updated";
    };
    void open(std::string);
    void click(){
        std::cout << "word clicked" << std::endl;
    };
    void doubleclick(){
    1;
    };

};

#endif