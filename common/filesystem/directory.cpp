#include <common/filesystem/directory.hpp>
#include <iostream>

#include <common/text/text.hpp>
extern TextRenderer * text;



void Directory::recurse(std::shared_ptr<disk_node> tree_node) {
    
    if (tree_node && tree_node->show_children && !tree_node->active) {
        std::cout << "in recurse";
        tree_node->active = 1;
        
        std::cout << "[Directory::recurse][common/filesystem/directory.cpp] node name:" << tree_node->name << std::endl;
        std::cout << "[Directory::recurse][common/filesystem/directory.cpp] node children count:" << tree_node->children.size() << std::endl;
        
        int test = 0;
        for (int i = 0; i < tree_node->children.size(); i++) {
            std::shared_ptr<disk_node> node_child = tree_node->children[i];
            if (node_child) {

                std::cout << "[Directory::recurse][common/filesystem/directory.cpp] node children name:" << node_child->name << std::endl;

                node_child->margin.back = 0.3;
                
                if (node_child->parent){
                    //problem here
                    
                    //not that usefull now, already habe siblings and order
                    node_child->parent = node_child->parent->handle;
//                    node_child->parent->children.push_back(node_child);
                }
                node_child->siblings_count = tree_node->children.size();
                node_child->order = std::find(tree_node->children.begin(), tree_node->children.end(), node_child) - tree_node->children.begin();
                node_child->color = glm::vec3(0,255,0);
                if(node_child->is_directory){
                    node_child->color = glm::vec3(255,0,0);
                }
                scene.AddElement(node_child);
                text->addElement(node_child);
                node_child->scene =  &scene;
                scene.changeElement(node_child);
                
                
            }
        }
    }
    for (std::shared_ptr<disk_node> node_child : tree_node->children) {
        this->recurse(node_child);
    }
}

Directory::Directory(std::string directory):
    dir(directory),
    path(directory),
    current_iteration(directory)
{
    extern std::vector<GLfloat> cube_shape;

    scene.setUp(&cube_shape);
    root_directory = std::shared_ptr<disk_node>(new disk_node());
    root_directory->handle = root_directory->shared_from_this();
    root_directory->color = glm::vec3(255,255,255);
    root_directory->dimension.width = root_directory->scale.x;
    root_directory->dimension.height = root_directory->scale.y;
    root_directory->dimension.depth = root_directory->scale.z;

    current_parent = root_directory->handle;
    std::cout << root_directory->coords.x << root_directory->coords.y << root_directory->coords.z << "in directory root\n";
    
    root_directory->scene =  &scene;
    root_directory->is_directory = true;
    root_directory->name = "aaa";
    scene.AddElement(root_directory);
    
//    width(.03f), height(.01f), depth(.003f)

    
    std::cout << "[common/filesystem/directory.cpp][Directory::Directory] root directory pointer:" << this->root_directory << std::endl;
    text->addElement(root_directory);
    scene.changed = true;
    
    boost::filesystem::recursive_directory_iterator end;
    while (this->current_iteration != end) {
        std::shared_ptr<disk_node> current_directory_iteration = std::shared_ptr<disk_node>(new disk_node());
        current_directory_iteration->handle = current_directory_iteration->shared_from_this();
        current_directory_iteration->name = this->current_iteration->path().filename().string();

        this->find_parent();
        current_directory_iteration->parent = this->current_parent->handle;
        this->current_parent->children.push_back(current_directory_iteration);

        if (boost::filesystem::is_directory(this->current_iteration->path())) {
            current_directory_iteration->is_directory = true;
            this->current_parent = current_directory_iteration->handle;
        }

        this->current_iteration++;
    }
}

void Directory::find_parent() {
    auto parent = this->current_parent;
    //in case the current parent is current directory iteration, return to keep the current parent
    if (this->current_iteration->path().parent_path().string() + "/" == this->build_path(parent)) return;

    while (this->current_iteration->path().parent_path().string() + "/" != this->build_path(parent)) {
        if (parent->parent) {
            parent = parent->parent;
        } else {
            return;
        }
    }
    this->current_parent = parent;
}

std::string Directory::build_path(std::shared_ptr<disk_node> parent) {
    std::string compound;
    while (parent) {
        compound = parent->name + "/" +  compound;
        if (parent->parent) {
            parent = parent->parent;
        } else {
            parent.reset();
        }
    }
    return this->dir + compound;
}

std::string Directory::get_path(std::shared_ptr<disk_node> parent) {
    bool isDir = parent->is_directory;
    std::string compound;
    while (parent) {
        compound = parent->name + "/" +  compound;
        if (parent->parent) {
            parent = parent->parent;
        } else {
            parent.reset();
        }
    }
    if(!isDir){
        compound.pop_back();
    }
    return this->dir + compound;
}

void Directory::update() {
    this->recurse(this->root_directory);
}
