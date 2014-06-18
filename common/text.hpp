#ifndef TEXT_HPP
#define TEXT_HPP
#include <ft2build.h>
#include FT_FREETYPE_H
#include <common/types.hpp>
#include <GL/glew.h>
#include <fstream>
class TextRenderer{
public:
    TextRenderer(const char);
    TextRenderer();
private:
    FT_Face face;
    void create_letter_faces(const char);
    void add_letter_point(point2d, int *);
    std::vector<int> letter_indices;
    std::vector<point2d> letter_points;
};


#endif