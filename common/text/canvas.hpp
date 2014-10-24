#ifndef CANVAS
#define CANVAS
#include <vector>
#include <common/handle.hpp>
#include <common/space/object3d.hpp>
#include <memory>
#include <iostream>
#include <common/space/scene.hpp>
#include <common/text/word.hpp>

#include <common/text/text.hpp>
extern TextRenderer * text;

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

    Canvas(): name(""), Object3d(new Canvas3dProperties) {
        this->cursor = this->coords;
    };
    
    std::shared_ptr<Canvas> handle;
    bool active;
    GLfloat cursor_width;
    GLfloat cursor_height;
    glm::vec3 cursor;

    std::string name;
    std::vector<std::shared_ptr<Word> > children;
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
        
        cursor_width += word->dimension.width + 0.003;

    }
    void click(){
        std::cout << "Canvas clicked" << std::endl;
    }
    void doubleclick(){
    1;
    }

    void descendCursor(){
        this->cursor.y -= 0.01;
        this->cursor.x = this->coords.x;
    }

    void advanceCursor(GLfloat width){
        this->cursor.x += width;
    }

    void addLine(std::string & string){

        std::string string_part = "";



        for(char & c : string){

            if(c == ' ' || c == string.back()){
                if(string_part.length() > 0){
                    this->addWord(string_part);
                } else {
                    this->advanceCursor(0.005);
                }
                string_part = "";
            } else {
                string_part += c;
            }
        }
        this->descendCursor();

    }

    void addWord(std::string & string_part){
        Word3dProperties * props = new Word3dProperties();
        props->coords = this->cursor;
        props->string = string_part;
        std::shared_ptr<Word> word = std::make_shared<Word>(props,text);
        word->handle = word->shared_from_this();
        this->children.push_back(word->handle);
        this->advanceCursor(word->width+ 0.005);
    }

};

#endif
