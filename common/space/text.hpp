

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

#include <common/space/scene.hpp>

#define MIN_FACTOR 200000

//class Label{
//public:
//    Label();
//    std::string name;
//    SpatialObject spatial_construct;
//private:
//};




class Letter {
public:
    Letter(const char);
    Letter(){};
    ArraysInstanced scene;
    int thickness;
    int triangles;
    GLfloat width, height, offsetx;
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


// Include GLEW

class TextRenderer {
public:
    TextRenderer();

    template <class has_text >
    void addElement(std::shared_ptr<has_text> obj) {
        glm::vec3 position = obj->coords;

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

        for (char& c : obj->name) {
            obj->dimension.width += this->letters[static_cast<int> (c)]->width / (GLfloat) MIN_FACTOR;
        }
        props.coords.x -= obj->dimension.width / 2;


        for (char& c : obj->name) {
            props.coords.x += (this->letters[static_cast<int> (c)]->width / (GLfloat) MIN_FACTOR) - (this->letters[static_cast<int> (c)]->offsetx / (GLfloat) MIN_FACTOR);

            props.dimension.width = 1 / (GLfloat) MIN_FACTOR;
            props.dimension.height = 1 / (GLfloat) MIN_FACTOR;
            SpatialObjectExpanded obj = std::make_shared<Object3dExpanded>(&props);
            this->letters[static_cast<int> (c)]->scene.AddElement(obj);
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