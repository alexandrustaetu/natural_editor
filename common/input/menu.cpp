#include <common/input/menu.hpp>

#include <common/text/text.hpp>
extern TextRenderer * text;

//void defaultMenu(){
//    std::cout << "building default menu";
//}

Menu::Menu(){
    
    extern std::vector<GLfloat> cube_shape;

    this->scene.setUp(&cube_shape);
    
}

void Menu::create(glm::vec3 * coords){
    Object3dProperties props;
    props.coords = * coords;
    props.dimension.width = props.scale.x = 0.03;
    props.dimension.height = props.scale.y = 0.01;
    props.dimension.depth = props.scale.z = 0.001;

    props.color = glm::vec3(111,111,111);
    this->spatial_construct = std::make_shared<Object3dExpanded>(&props);
    this->scene.AddElement(this->spatial_construct);
    
    MenuProps menu_props;

    SpatialObjectExpanded option1 = std::make_shared<Object3dExpanded>(&menu_props);
    this->spatial_construct->addChild(option1);
    text->label(option1,"new");
    this->scene.AddElement(option1);
    
    SpatialObjectExpanded option2 = std::make_shared<Object3dExpanded>(&menu_props);
    this->spatial_construct->addChild(option2);
    text->label(option2,"properties");
    this->scene.AddElement(option2);
}


