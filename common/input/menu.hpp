#ifndef MENU
#define MENU

#include <common/space/object3d.hpp>
#include <common/space/text.hpp>
//#include <common/space/helper.hpp>
//void defaultMenu();

class Menu
{
public:
    SpatialObjectExpanded spatial_construct;
    Menu(){};
    ArraysInstanced scene;
    Menu(TextRenderer *,btDiscreteDynamicsWorld*);
    TextRenderer * text;
    btDiscreteDynamicsWorld* physics;
    void create(glm::vec3 *);
private:
};

#endif