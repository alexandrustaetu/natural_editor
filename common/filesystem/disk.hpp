#ifndef DISK
#define DISK
#include <vector>
#include <common/handle.hpp>
#include <common/space/object3d.hpp>
#include <memory>
#include <iostream>

class disk_node  : 
//public Object3dExpanded
public Object3d<disk_node>
{
public:

    disk_node(): is_directory(false), name(""), Object3d(new Object3dProperties) {};
    disk_node(bool);
    
    std::shared_ptr<disk_node> handle;
    bool is_directory;
    std::string name;
    std::vector<std::shared_ptr<disk_node> > children;
    std::shared_ptr<disk_node> parent;
    void update();
    void click();

};

typedef std::vector< std::shared_ptr<disk_node> > disk_nodes;

#endif