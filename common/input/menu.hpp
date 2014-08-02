#ifndef MENU
#define MENU

#include <common/space/object3d.hpp>
#include <common/space/scene.hpp>
//#include <common/space/helper.hpp>
//void defaultMenu();

class Menu
{
public:
    SpatialObjectExpanded spatial_construct;
    ArraysInstanced scene;
    Menu();
    void create(glm::vec3 *);
private:
};

#endif