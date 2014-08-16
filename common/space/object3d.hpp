#ifndef OBJECT3D
#define OBJECT3D

#include <common/handle.hpp>
#include <common/space/physics.hpp>
#include <common/space/helper.hpp>


#include <common/environment/debug_frame.hpp>

class DebugFrame;
extern DebugFrame * debugFrame;

template <class T>
class Object3d : virtual public virtual_handle
//public Handle<Object3d> 
{
public:

    Object3d() {
    };
    bool has_physics, visible, show_children, clicked;
    std::shared_ptr<Object3d> handle;
    glm::vec3 origin, destination, coords, color, scale;
    margins margin;
    int position;
    int siblings_count, order, sceneIndex;
    std::shared_ptr<Physics> physics;
    dimensions dimension;
    std::vector<std::shared_ptr<Object3d> > children;
    std::shared_ptr<Object3d> parent;
    std::shared_ptr<Object3d> group;

    void setCoords(glm::vec3 * coords) {
        this->coords = coords;
    };

    template <class T2>
    void update(std::shared_ptr<T2>) {
        if (parent) {
            this->origin = parent->origin;
            this->destination.x = this->origin.x + 2;
            this->destination.y = this->origin.y + 2;
            this->destination.z = this->origin.z + 2;
        }
    };

    template <class T2>
    void setGroup(std::shared_ptr<T2>);

    void changeColor(glm::vec3 color) {
        this->color = color;
        std::cout << "[common/space/object3d.cpp][Object3d::changeColor] color changed" << std::endl;
    };

    virtual void click() {
        std::cout << "clicked\n";
        //        this->clicked = true;
    };

    void rightclick() {
        std::cout << this->handle << std::endl;
    };

    virtual void doubleclick() {
        this->show_children = true;
        std::cout << "show children" << std::endl;
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

    Object3d(Object3dProperties * props) : siblings_count(0), visible(true), position(ABSOLUTE) {

        this->coords = props->coords;
        this->destination = props->destination;

        this->position = props->position;

        this->origin = props->origin;

        this->color = props->color;
        if (props->has_physics) {
            this->physics = std::shared_ptr<Physics>(new Physics(props));
        }
        this->dimension = props->dimension;
        this->scale = props->scale;
        this->show_children = props->show_children;
    };
//    template <class T2>
    std::shared_ptr<T> shared_from_this();

};

class Object3dExpanded
: public Object3d<Object3dExpanded> {
public:

    Object3dExpanded() {
    };
    //template <class T>

    Object3dExpanded(Object3dProperties * props)
    : Object3d(props) {
    };
};


#ifndef DEBUGFRAME
#define DEBUGFRAME
//    DebugFrame * debugFrame = new DebugFrame();
#endif
extern std::shared_ptr<Object3dExpanded> DebugFrame;   

template <class T>
template <class T2>
void Object3d<T>::setGroup(std::shared_ptr<T2> group) {
    int a {1};
//    std::shared_ptr<Object3d<T> > n = static_cast<std::shared_ptr<Object3d<T> > >(group); 
//    std::static_cast<int*>("aaa");
//    std::static_cast<Object3d<T> (DebugFrame);
    
//    this->group = group;
};


template <class T>
//template <class T2>
std::shared_ptr<T> Object3d<T>::shared_from_this() {

    std::shared_ptr<T> objectHandle = std::dynamic_pointer_cast<T>(virtual_handle::shared_from_this());
    
//    int zuzu = std::static_cast<int>(DebugFrame);
//    this->setGroup(DebugFrame);
    //        debugFrame->registerObject( this);

    return objectHandle;
}


//typedef std::shared_ptr<Object3d> SpatialObject;
typedef std::shared_ptr<Object3dExpanded> SpatialObjectExpanded;


template <class T>
using SpatialObject = std::shared_ptr<Object3d<T> >;

typedef std::vector<std::shared_ptr<SpatialObjectExpanded> > Object3dVector;

#endif
