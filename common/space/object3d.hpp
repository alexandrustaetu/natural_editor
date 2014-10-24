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
    int getWidth(){
        return dimension.width + margin.left + margin.right;
    }
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

    void showChildren(){
        show_children = true;
    };

    void setCoords(glm::vec3 * coords) {
        coords = coords;
    };

    template <class T2>
    void update(std::shared_ptr<T2>) {
        if (parent) {
            origin = parent->origin;
            //TODO why +2
            destination.x = origin.x + 2;
            destination.y = origin.y + 2;
            destination.z = origin.z + 2;
        }
    };

    template <class T2>
    void setGroup(std::shared_ptr<T2>);

    void changeColor(glm::vec3 color) {
        color = color;
        std::cout << "[common/space/object3d.cpp][Object3d::changeColor] color changed" << std::endl;
    };

    virtual void click() {
        std::cout << "clicked\n";
        //        this->clicked = true;
    };

    void rightclick() {
        std::cout << handle << std::endl;
    };

    virtual void doubleclick() {
        show_children = true;
        std::cout << "show children" << std::endl;
    };

    template <class T2>
    void addChild(std::shared_ptr<T2> child){
        if (child->position == RELATIVE) {
            std::cout << "children added to 3d object\n";
            std::shared_ptr<Object3d> last_child;

            //Get last relative child for parent
            for (auto child : children) {
                if (child->position == RELATIVE) {
                    last_child = child;
                }
            }
            //If
            if (last_child) {
                if (child->dimension.width + last_child->dimension.width < this->dimension.width) {
                    child->coords.x = last_child->coords.x + last_child->margin.right + child->margin.left;
                    child->coords.y = last_child->coords.y;
                } else {
                    child->coords.y = last_child->coords.y;
                    child->coords.x = coords.x - dimension.width / 2;
                }
            } else {
                child->coords.x = coords.x;// - dimension.width / 2;// - child->dimension.width/2;
                child->coords.y = coords.y - dimension.height / 2 - child->dimension.height/2;
            }
            child->coords.z = coords.z;

            addMargins(child);

        }
    };

    template <class T2>
    void addMargins(std::shared_ptr<T2> object) {
        if(object->margin.left > 0){
            object->coords.x -= object->margin.left;
        } else if (object->margin.right > 0){
            object->coords.x += object->margin.right;
        }

        if(object->margin.top > 0){
            object->coords.y -= object->margin.top;
        } else if (object->margin.bottom > 0){
            object->coords.y += object->margin.bottom;
        }

        if(object->margin.front > 0){
            object->coords.z -= object->margin.front;
        } else if (object->margin.back > 0){
            object->coords.z += object->margin.back;
        }
    }

    Object3d(Object3dProperties * props) : siblings_count(0), visible(true), position(ABSOLUTE) {

        coords = props->coords;
        destination = props->destination;

        position = props->position;

        origin = props->origin;

        color = props->color;
        if (props->has_physics) {
            physics = std::shared_ptr<Physics>(new Physics(props));
        }
        dimension = props->dimension;
        scale = props->scale;
        show_children = props->show_children;
        margin = props->margin;
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
