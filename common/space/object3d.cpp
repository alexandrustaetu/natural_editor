#include "object3d.hpp"
#include <iostream>
//template <class T>
//Object3d<T>::Object3d(Object3dProperties * props) : siblings_count(0), visible(true), position(ABSOLUTE) {
//    this->position = props->position;
//    this->coords = props->coords;
//    this->color = props->color;
//    if (props->has_physics) {
//        this->physics = std::shared_ptr<Physics>(new Physics(props));
//    }
//    this->dimension = props->dimension;
//    this->show_children = props->show_children;
//}
//template <class T>
//template <class T2>
//void Object3d<T>::update(std::shared_ptr<T2> parent) {
//    if (parent) {
//        this->origin = parent->origin;
//        this->destination.x = this->origin.x + 2;
//        this->destination.y = this->origin.y + 2;
//        this->destination.z = this->origin.z + 2;
//    }
//}
//template <class T>
//void Object3d<T>::click() {
//    this->clicked = true;
//}
//template <class T>
//void Object3d<T>::rightclick() {
//    std::cout << this->handle << std::endl;
//}
//template <class T>
//void Object3d<T>::doubleclick() {
//    this->show_children = true;
//}
//template <class T>
//template <class T2>
//void Object3d<T>::addChildren(std::shared_ptr<T2> children) {
//    if (children->position == RELATIVE) {
//        std::cout << "children added to 3d object\n";
//        std::shared_ptr<Object3d> last_child;
//        for (auto child : this->children) {
//            if (child->position == RELATIVE) {
//                last_child = child;
//            }
//        }
//        if (last_child) {
//            if (children->dimension.width + last_child->dimension.width < this->dimension.width) {
//                children->coords.x = last_child->coords.x + last_child->margin.right + children->margin.left;
//                children->coords.y = last_child->coords.y;
//            } else {
//                children->coords.y = last_child->coords.y;
//                children->coords.x = this->coords.x - this->dimension.width / 2;
//            }
//        } else {
//            children->coords.x = this->coords.x - this->dimension.width / 2;
//            children->coords.y = this->coords.y - this->dimension.height / 2;
//        }
//    }
//}

