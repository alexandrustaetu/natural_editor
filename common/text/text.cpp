#include <common/text/text.hpp>

#include <iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_face_base_with_info_2.h>
#include <CGAL/Polygon_2.h>

#include <common/environment/world.hpp>
extern World * world;

void Letter::Line(float x1, float y1, float x2, float y2) {

    this->myfile.open("/tmp/triangulation.dat", std::ios::app);
    // Bresenham's line algorithm
    const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
    if (steep) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    const float dx = x2 - x1;
    const float dy = fabs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int) y1;

    const int maxX = (int) x2;

    for (int x = (int) x1; x < maxX; x++) {
        if (steep) {

            this->myfile << y << " " << x << "\n";
        } else {

            this->myfile << x << " " << y << "\n";
        }

        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
    this->myfile.close();
}

struct FaceInfo2 {

    FaceInfo2() {
    }
    int nesting_level;

    bool in_domain() {
        return nesting_level % 2 == 1;
    }
};
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_2<K> Vb;
typedef CGAL::Triangulation_face_base_with_info_2<FaceInfo2, K> Fbb;
typedef CGAL::Constrained_triangulation_face_base_2<K, Fbb> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb, Fb> TDS;
typedef CGAL::Exact_predicates_tag Itag;
typedef CGAL::Constrained_Delaunay_triangulation_2<K, TDS, Itag> CDT;
typedef CDT::Point Point;
typedef CGAL::Polygon_2<K> Polygon_2;

void mark_domains(CDT& ct,
        CDT::Face_handle start,
        int index,
        std::list<CDT::Edge>& border) {
    if (start->info().nesting_level != -1) {
        return;
    }
    std::list<CDT::Face_handle> queue;
    queue.push_back(start);
    while (!queue.empty()) {
        CDT::Face_handle fh = queue.front();
        queue.pop_front();
        if (fh->info().nesting_level == -1) {
            fh->info().nesting_level = index;
            for (int i = 0; i < 3; i++) {
                CDT::Edge e(fh, i);
                CDT::Face_handle n = fh->neighbor(i);
                if (n->info().nesting_level == -1) {
                    if (ct.is_constrained(e)) border.push_back(e);
                    else queue.push_back(n);
                }
            }
        }
    }
}

void
mark_domains(CDT& cdt) {
    for (CDT::All_faces_iterator it = cdt.all_faces_begin(); it != cdt.all_faces_end(); ++it) {
        it->info().nesting_level = -1;
    }
    std::list<CDT::Edge> border;
    mark_domains(cdt, cdt.infinite_face(), 0, border);
    while (!border.empty()) {
        CDT::Edge e = border.front();
        border.pop_front();
        CDT::Face_handle n = e.first->neighbor(e.second);
        if (n->info().nesting_level == -1) {
            mark_domains(cdt, n, e.first->info().nesting_level + 1, border);
        }
    }
}

void insert_polygon(CDT& cdt, const Polygon_2& polygon) {
    if (polygon.is_empty()) return;
    CDT::Vertex_handle v_prev = cdt.insert(*CGAL::cpp11::prev(polygon.vertices_end()));
    for (Polygon_2::Vertex_iterator vit = polygon.vertices_begin();
            vit != polygon.vertices_end(); ++vit) {
        CDT::Vertex_handle vh = cdt.insert(*vit);
        cdt.insert_constraint(vh, v_prev);
        v_prev = vh;
    }
}

float slope(FT_Vector point_a, FT_Vector point_b) {
    if (point_b.x == point_a.x)point_a.x++;
    return (float) (point_b.y - point_a.y) / (float) (point_b.x - point_a.x);
}

void segment_points(FT_Vector first_point, FT_Vector second_point, Polygon_2 * polygon) {
    polygon->push_back(Point(first_point.x - 1, first_point.y - 1));
    polygon->push_back(Point(second_point.x, second_point.y));
}

void bezier_conic_points(FT_Vector first_point, FT_Vector second_point, FT_Vector third_point, Polygon_2 * polygon) {
    FT_Vector start_point, prev_point, current_point;
    start_point = prev_point = first_point;
    float prev_slope, start_slope, current_slope;

    bool start = true;
    for (double t = 0; t <= 1; t += 0.1) {
        current_point.x = (1 - t)*(1 - t) * first_point.x + 2 * (1 - t) * t * second_point.x + t * t * third_point.x;
        current_point.y = (1 - t)*(1 - t) * first_point.y + 2 * (1 - t) * t * second_point.y + t * t * third_point.y;
        current_slope = slope(start_point, current_point);

        if (start) {
            start = false;
            start_slope = current_slope;
        } else {

            if (std::abs(std::abs(start_slope) - std::abs(current_slope)) > 0.1) {
                start_point = prev_point;
                start_slope = prev_slope;
                start = true;

                if (t != 1) {
                    polygon->push_back(Point(current_point.x, current_point.y));
                }
            }
        }
        prev_point = current_point;
        prev_slope = current_slope;
    }
}

FT_Library ft;

const char *fontfilename;

Letter::Letter(const char character) : thickness(0) {
//    this->scene.setPhysics(world->physics);
    fontfilename = "OpenSans-Regular.ttf";
    std::cout << "\n\nchar initiated\n\n";
    if (FT_Init_FreeType(&ft)) {
        fprintf(stderr, "Could not init freetype library\n");
    }
    if (FT_New_Face(ft, fontfilename, 0, &this->face)) {
        fprintf(stderr, "Could not open font %s\n", fontfilename);
    }
    FT_Set_Pixel_Sizes(this->face, 10, 14);
    this->create_letter_faces(character);
}

void Letter::create_letter_faces(const char letter) {
    FT_GlyphSlot g = this->face->glyph;
    int end_point;
    CDT cdt;
    int start_point = 0;
    if (FT_Load_Char(this->face, letter, FT_LOAD_DEFAULT))
        exit(3);
    this->offsetx = (GLfloat)g->metrics.horiBearingX;
    this->height = (GLfloat)g->metrics.horiAdvance;
    this->width = (GLfloat)g->metrics.vertAdvance;
    for (int current_contour = 0; current_contour < g->outline.n_contours; current_contour++) {

        Polygon_2 polygon;

        end_point = g->outline.contours[current_contour];

        for (int current_point = start_point; current_point <= end_point; current_point++) {

            if (current_point == end_point) {
                std::bitset<8>start_tags(g->outline.tags[start_point]);
                std::bitset<8>end_tags(g->outline.tags[end_point]);
                FT_Vector contour_start = g->outline.points[start_point];
                FT_Vector contour_end = g->outline.points[end_point];

                if (end_tags[0] == FT_CURVE_TAG_ON) {
                    if (start_tags[0] == FT_CURVE_TAG_ON) {
                        segment_points(contour_start, contour_end, &polygon);
                    }
                }

            } else {
                std::bitset<8>first_tags(g->outline.tags[current_point]);
                FT_Vector first_point = g->outline.points[current_point];
                current_point++;
                std::bitset<8>second_tags(g->outline.tags[current_point]);
                FT_Vector second_point = g->outline.points[current_point];

                if (first_tags[0] == FT_CURVE_TAG_ON) {
                    if (second_tags[0] == FT_CURVE_TAG_ON) {
                        segment_points(first_point, second_point, &polygon);
                        current_point--;
                    } else {
                        std::bitset<8>third_tags(g->outline.tags[current_point + 1]);

                        if (end_point == current_point) {
                            std::bitset<8>start_tags(g->outline.tags[start_point]);

                            if (start_tags[0] == FT_CURVE_TAG_ON) {
                                FT_Vector third_point = g->outline.points[start_point];
                                bezier_conic_points(first_point, second_point, third_point, &polygon);
                            } else {
                                1;
                            }
                        } else {
                            if (third_tags[0] == FT_CURVE_TAG_ON) {
                                FT_Vector third_point = g->outline.points[current_point + 1];
                                bezier_conic_points(first_point, second_point, third_point, &polygon);
                            } else {
                                FT_Vector third_point = g->outline.points[current_point + 1];
                                FT_Vector virtual_third_point;
                                virtual_third_point.x = second_point.x - (second_point.x - third_point.x) / 2;
                                virtual_third_point.y = second_point.y - (second_point.y - third_point.y) / 2;
                                bezier_conic_points(first_point, second_point, virtual_third_point, &polygon);
                                g->outline.tags[current_point] = '1';
                                g->outline.points[current_point] = virtual_third_point;
                                current_point--;
                            }
                        }
                    }
                } else {
                    //tag is off
                }
            }
        }
        start_point = end_point + 1;
        insert_polygon(cdt, polygon);
    }

    mark_domains(cdt);

    int count = 0;

    for (CDT::Finite_faces_iterator fit = cdt.finite_faces_begin();
            fit != cdt.finite_faces_end(); ++fit) {
        if (fit->info().in_domain()) {
            this->triangles++;

            this->letter_points.push_back(fit->vertex(0)->point().x());
            this->letter_points.push_back(fit->vertex(0)->point().y());
            this->letter_points.push_back(this->thickness);
            this->letter_points.push_back(fit->vertex(1)->point().x());
            this->letter_points.push_back(fit->vertex(1)->point().y());
            this->letter_points.push_back(this->thickness);
            this->letter_points.push_back(fit->vertex(2)->point().x());
            this->letter_points.push_back(fit->vertex(2)->point().y());
            this->letter_points.push_back(this->thickness);
            this->letter_points.push_back(fit->vertex(2)->point().x());
            this->letter_points.push_back(fit->vertex(2)->point().y());
            this->letter_points.push_back(0.0f);
            this->letter_points.push_back(fit->vertex(1)->point().x());
            this->letter_points.push_back(fit->vertex(1)->point().y());
            this->letter_points.push_back(0.0f);
            this->letter_points.push_back(fit->vertex(0)->point().x());
            this->letter_points.push_back(fit->vertex(0)->point().y());
            this->letter_points.push_back(0.0f);


            if (this->thickness != 0.0f) {
                //sides
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);


                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);


                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);


                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(1)->point().x());
                this->letter_points.push_back(fit->vertex(1)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);

                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(2)->point().x());
                this->letter_points.push_back(fit->vertex(2)->point().y());
                this->letter_points.push_back(this->thickness);
                this->letter_points.push_back(fit->vertex(0)->point().x());
                this->letter_points.push_back(fit->vertex(0)->point().y());
                this->letter_points.push_back(0.0f);
            }
        }
    }

    this->scene.SetIndices(&this->letter_points);
}

TextRenderer::TextRenderer() {
    this->physics = world->physics;
    Object3dProperties props;
    props.has_physics = false;
    for (int i = 0; i < 127; i++) {
        this->letters.push_back(new Letter(static_cast<char> (i)));
    }
    std::cout << this->letters.size();

}

void TextRenderer::addString(std::string * string){
    for(char& c : *string) {
        std::cout << c << std::endl;
    }
    
}

void TextRenderer::draw(glm::mat4 * mvp){
    for(Letter * letter : this->letters) {
        letter->scene.draw(mvp);
    }
}


void TextRenderer::label(SpatialObjectExpanded object,std::string name){
    
    GLfloat width = 0.0;
    
    Object3dProperties props;
    props.position = RELATIVE;
    props.dimension.width = 0;
    props.dimension.height = 0.01;
    props.color = glm::vec3(0,0,111);
//    this->name = name;
    
    for(char& c : name) {
       width += this->letters[static_cast<int> (c)]->width/(GLfloat)MIN_FACTOR;
    }
    std::cout << width << std::endl;
//    this->spatial_construct = std::make_shared<Object3d>(&props);
}