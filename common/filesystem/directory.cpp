#include <common/filesystem/directory.hpp>
#include <iostream>

#include <common/space/text.hpp>
extern TextRenderer * text;

void Directory::recurse(std::shared_ptr<disk_node> tree_node) {
    if (tree_node && tree_node->show_children) {
        for (std::shared_ptr<disk_node> node_child : tree_node->children) {
            std::cout << tree_node->children.size()<< "in directory recurse" << node_child << std::endl;
            if (node_child) {
                node_child->margin.back = 0.3;
                
                if (node_child->parent){
                    //problem here
                    
                    //not that usefull now, already habe siblings and order
                    node_child->parent = node_child->parent->handle;
                    node_child->parent->children.push_back(node_child);
                }
                node_child->siblings_count = tree_node->children.size();
                node_child->order = std::find(tree_node->children.begin(), tree_node->children.end(), node_child) - tree_node->children.begin();
                node_child->color = glm::vec3(0,255,0);
                if(node_child->is_directory){
                    node_child->color = glm::vec3(255,0,0);
                }
                this->scene.AddElement(node_child);
                text->addElement(node_child);
                this->scene.changeElement(node_child);
                
            }
        }
    }
    for (std::shared_ptr<disk_node> node_child : tree_node->children) {
        recurse(node_child);
    }
}

Directory::Directory(std::string directory) : path(directory), current_iteration(directory) {
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
    this->root_directory = std::shared_ptr<disk_node>(new disk_node());
    this->root_directory->handle = this->root_directory->shared_from_this();
    this->root_directory->color = glm::vec3(255,255,255);
    this->current_parent = this->root_directory->handle;
    std::cout << this->root_directory->coords.x << this->root_directory->coords.y << this->root_directory->coords.z << "in directory root\n"; 
    this->scene.AddElement(this->root_directory);
    text->addElement(this->root_directory);
    this->scene.changed = true;

    
    
    
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
    return this->path.string() + compound;
}

void Directory::update() {
    recurse(this->root_directory);
}