#ifndef MENU
#define MENU

#include <common/space/scene.hpp>

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