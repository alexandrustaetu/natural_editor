

#ifndef LETTER
#define LETTER
#include <memory>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <common/types.hpp>
#include <GL/glew.h>
#include <fstream>
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



#endif
