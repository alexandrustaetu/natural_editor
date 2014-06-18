#include <common/input/menu.hpp>
//void defaultMenu(){
//    std::cout << "building default menu";
//}

Menu::Menu(TextRenderer * text,btDiscreteDynamicsWorld* physics){
    this->text = text;
    
    std::vector<GLfloat> file_shape({
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f
    });

    this->scene.SetIndices(&file_shape);
    this->scene.setPhysics(physics);
    
}

void Menu::create(glm::vec3 * coords){
    Object3dProperties props;
    props.coords = * coords;
    props.dimension.width = 0.10;
    props.color = glm::vec3(111,111,111);
    this->spatial_construct = std::make_shared<Object3dExpanded>(&props);
    this->scene.AddElement(this->spatial_construct);
    
    
    props.color = glm::vec3(111,111,0);
    props.position = RELATIVE;
    SpatialObjectExpanded option1 = std::make_shared<Object3dExpanded>(&props);
    this->spatial_construct->addChildren(option1);
    this->text->label(option1,"new");
    this->scene.AddElement(option1);
    
    SpatialObjectExpanded option2 = std::make_shared<Object3dExpanded>(&props);
    this->spatial_construct->addChildren(option2);
    this->text->label(option2,"properties");
    this->scene.AddElement(option2);
}


