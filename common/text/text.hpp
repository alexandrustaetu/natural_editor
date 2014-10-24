

#ifndef TEXT3D
#define TEXT3D
#include <memory>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <common/types.hpp>
#include <GL/glew.h>
#include <fstream>
#include <common/text/word.hpp>
#include <common/text/letter.hpp>
#include <common/space/scene.hpp>

#define MIN_FACTOR 200000

//class Label{
//public:
//    Label();
//    std::string name;
//    SpatialObject spatial_construct;
//private:
//};



/*
class Letter {
public:
    Letter(const char);
    Letter(){};
    ArraysInstanced scene;
    int thickness;
    int triangles;
    GLfloat width, height, offsetx, offsety;
    void create_letter_faces(const char);
    std::vector<int> letter_indices;
    std::vector<GLfloat> letter_points;
private:
    std::map< int, std::vector<int> > x_coords;
    std::map< int, std::vector<int> > y_coords;
    std::ofstream myfile;
    FT_Face face;
    void Line(float x1, float y1, float x2, float y2);
};
*/

// Include GLEW

class TextRenderer {
public:
    TextRenderer();

    template <class has_text >
    void addElement(std::shared_ptr<has_text> obj) {
        //////////////WORD
        Word3dProperties * word_props = new Word3dProperties();
        word_props->string =obj->name;
        //Word * element_word = new Word(obj);
        //////////////
        glm::vec3 position = obj->coords;
        GLfloat letter_posx =obj->coords.x;
        Object3dProperties props;
        props.has_physics = false;
        props.coords = obj->coords;
        props.coords.z -= -0.005;

        props.margin.back = 0;
        props.margin.front = 0;
        props.margin.left = 0;
        props.margin.right = 0;
        props.margin.top = 0;
        props.margin.bottom = 0;
        obj->dimension.width = 0.00;

        //increase the width of the parent . This will help when printing labels
        for (char& c : obj->name) {
            //converting the letter to asci int
            int letter_int = static_cast<int> (c);
            if(letter_int > 127){
                //if we do not have the letter loaded in the memory, replace it with "|"
                letter_int = 124;
            }
            obj->dimension.width += this->letters[letter_int]->width;
        }

        //Center the element
        props.coords.x -= obj->dimension.width / 2;


        for (char& c : obj->name) {

            Letter * letter =this->letters[static_cast<int> (c)];

            Object3dProperties letterprops = props;

            letterprops.coords.x += letter->width - letter->offsetx;

            letterprops.dimension.width = letter->width;
            letterprops.dimension.height = letter->height;
            letterprops.scale = glm::vec3(1,1,1);
            letterprops.coords.y -= letter->offsety;
            letterprops.coords.x = letter_posx;
            SpatialObjectExpanded obj1 = std::make_shared<Object3dExpanded>(&letterprops);
            letter->scene.AddElement(obj1);
            letter_posx += letter->width;
        }
    };
    void draw(glm::mat4 * mvp);
    void label(SpatialObjectExpanded,std::string);
    void addString(std::string*);
    std::vector<Letter*> letters;
private:
    btDiscreteDynamicsWorld* physics;
};

#endif
