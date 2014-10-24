#ifndef WORD
#define WORD
#include <vector>
#include <common/handle.hpp>
#include <common/space/object3d.hpp>
#include <memory>
#include <iostream>
#include <common/space/scene.hpp>
//#include <common/text/canvas.hpp>
#include <common/text/letter.hpp>

#include <GL/glew.h>

class Word3dProperties : public Object3dProperties {
    public:
        std::string string;
        Word3dProperties(){
            this->position = RELATIVE;
        };
};

class Word  : 
public Object3d<Word>
{
public:

    Word(Word3dProperties * props): name(""), Object3d(props) {};
    template <class text_renderer>
    Word(Word3dProperties * props, text_renderer * textrenderer): name(props->string),Object3d(props) {

        this->cursor = props->coords;
        this->width = 0;
        for(char & c : props->string){
            this->addLetter(c,textrenderer);

        }
    };
    Word(): name(""), Object3d(new Word3dProperties) {};
    ArraysInstanced * scene;
    glm::vec3 cursor;
    std::shared_ptr<Word> handle;
    std::vector<SpatialObjectExpanded> letters;
    bool active;
    bool next_line;
    std::string name;
    GLfloat width;

    std::vector<std::shared_ptr<Word> > children;
    void update(){};
    void open(std::string);
    void click(){
        std::cout << "word clicked" << std::endl;
    };
    void doubleclick(){
    1;
    };
    template <class text_renderer>
    void addLetter(char c,text_renderer * textrenderer){
        Letter * letter = textrenderer->letters[static_cast<int> (c)];
        this->cursor.x += letter->width;
        this->width += letter->width;
        Object3dProperties letterprops;
        letterprops.scale = glm::vec3(1,1,1);
        letterprops.coords = this->cursor;

        SpatialObjectExpanded obj1 = std::make_shared<Object3dExpanded>(&letterprops);
        obj1->handle = obj1->shared_from_this();
        obj1->dimension.width = letter->width;
        this->letters.push_back(obj1);

        letter->scene.AddElement(obj1);

    }
};

#endif
