#include <common/filesystem/disk.hpp>

//disk_node::disk_node(bool has_spatial_construct = false) : is_directory(false), name("") {
////    if (has_spatial_construct) {
////        Object3dProperties props;
////        this->spatial_construct = std::make_shared<Object3dExpanded>(&props);
////    }
//};

void disk_node::update() {
    if (this->parent) {
        Object3d::update(this->parent);
    }
}

void disk_node::doubleclick(){
    std::cout << "disk node dclicked\n";
    this->show_children = true;
}

void disk_node::click() {
    this->clicked = true;
    std::cout << "disk node clicked\n";
}