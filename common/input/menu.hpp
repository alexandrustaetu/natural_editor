#ifndef MENU
#define MENU

#include <common/space/scene.hpp>

class MenuProps : public Object3dProperties {

public:
    MenuProps()
    {
        color = glm::vec3(111,111,0);
        position = RELATIVE ;
        scale = glm::vec3(0.005,0.005,0.001);
        dimension.width = scale.x;
        dimension.height = scale.y;
        dimension.depth = scale.z;
        margin.back = 0.005;
    }
};

//void defaultMenu();

class Menu
{
public:
    SpatialObjectExpanded spatial_construct;
    ArraysInstanced scene;
    Menu();
    void create(glm::vec3 *);
    void draw(glm::mat4 * mvp){
        scene.draw(mvp);
    }
private:
};


class MenuOption  :
//public Object3dExpanded
public Object3d<MenuOption>
{
public:

    MenuOption(): is_directory(false), name(""), Object3d(new Object3dProperties) {};
    MenuOption(bool);

    ArraysInstanced * scene;
    std::shared_ptr<MenuOption> handle;
    bool is_directory,active;
    std::string name;
    std::vector<std::shared_ptr<MenuOption> > children;
    std::shared_ptr<MenuOption> parent;
    void update();
    void open(std::string);
    void click();
    void doubleclick();

};


#endif
