#ifndef OBJECT3D
#define OBJECT3D
// Include GLEW
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <memory>
#include <common/handle.hpp>
#include <common/space/physics.hpp>
#include <common/space/helper.hpp>

template <class T>
class Object3d : virtual public virtual_handle
//public Handle<Object3d> 
{
public:

    Object3d() {
    };
    bool has_physics, visible, show_children, clicked;
    std::shared_ptr<Object3d> handle;
    glm::vec3 origin, destination, coords, color;
    margins margin;
    int position;
    int siblings_count, order, sceneIndex;
    std::shared_ptr<Physics> physics;
    dimensions dimension;
    std::vector<std::shared_ptr<Object3d> > children;
    std::shared_ptr<Object3d> parent;

    template <class T2>
    void update(std::shared_ptr<T2>) {
        if (parent) {
            this->origin = parent->origin;
            this->destination.x = this->origin.x + 2;
            this->destination.y = this->origin.y + 2;
            this->destination.z = this->origin.z + 2;
        }
    };

    virtual void click() {
        std::cout << "clicked\n";
        this->clicked = true;
    };

    void rightclick() {
        std::cout << this->handle << std::endl;
    };

    void doubleclick() {
        this->show_children = true;
    };

    template <class T2>
    void addChildren(std::shared_ptr<T2> children) {
        if (children->position == RELATIVE) {
            std::cout << "children added to 3d object\n";
            std::shared_ptr<Object3d> last_child;
            for (auto child : this->children) {
                if (child->position == RELATIVE) {
                    last_child = child;
                }
            }
            if (last_child) {
                if (children->dimension.width + last_child->dimension.width < this->dimension.width) {
                    children->coords.x = last_child->coords.x + last_child->margin.right + children->margin.left;
                    children->coords.y = last_child->coords.y;
                } else {
                    children->coords.y = last_child->coords.y;
                    children->coords.x = this->coords.x - this->dimension.width / 2;
                }
            } else {
                children->coords.x = this->coords.x - this->dimension.width / 2;
                children->coords.y = this->coords.y - this->dimension.height / 2;
            }
        }
    };


//    Object3d(Object3dProperties *);

    Object3d(Object3dProperties * props) : siblings_count(0), visible(true), position(ABSOLUTE) {
        this->position = props->position;
        this->coords = props->coords;
        this->color = props->color;
        if (props->has_physics) {
            this->physics = std::shared_ptr<Physics>(new Physics(props));
        }
        this->dimension = props->dimension;
        this->show_children = props->show_children;
    }

    std::shared_ptr<T> shared_from_this() {
        return std::dynamic_pointer_cast<T>(virtual_handle::shared_from_this());
    }

};

class Object3dExpanded
: public Object3d<Object3dExpanded> {
public:

    Object3dExpanded() {
    };
    //template <class T>
    Object3dExpanded(Object3dProperties * props)
    : Object3d(props)
    {
    };
};


//typedef std::shared_ptr<Object3d> SpatialObject;
typedef std::shared_ptr<Object3dExpanded> SpatialObjectExpanded;


template <class T>
using SpatialObject = std::shared_ptr<Object3d<T> >;


#endif