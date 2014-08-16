#include <common/filesystem/disk.hpp>
#include <common/text/word.hpp>
#include <fstream>
#include <boost/algorithm/string.hpp>

#include <common/text/canvas.hpp>


#include <common/text/text.hpp>
extern TextRenderer * text;


#include <common/filesystem/directory.hpp>
extern Directory * project_directory;
//extern File * file;


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

void disk_node::doubleclick() {
    std::cout << "[common/filesystem/disk.cpp][disk_node::doubleclick] node name:" << this->name << std::endl;
    std::string filePath = project_directory->get_path(this->handle);
    if (this->is_directory) {
        this->show_children = true;
    } else {
        this->open(filePath);
        std::cout << "[common/filesystem/disk.cpp][disk_node::doubleclick] file path: " << filePath << std::endl;
    }
}

void disk_node::click() {
    this->clicked = true;
    this->color = glm::vec3(111, 255, 0);
    this->dimension.width = .03f;
    this->dimension.height = .01f;
    this->dimension.depth = .003f;
    this->scale = glm::vec3(.03,.01,.003);
    this->scene->changeElement(this);
    std::cout << "[common/filesystem/disk.cpp][disk_node::click] node name:" << this->name << std::endl;
    std::cout << "[common/filesystem/disk.cpp][disk_node::click] node pointer:" << this << std::endl;
}

void disk_node::open(std::string filePath) {
    
    std::shared_ptr<Canvas> canvas = std::shared_ptr<Canvas>(new Canvas());
    canvas->handle = canvas->shared_from_this();
    
    Word3dProperties * wordToCanvas = new Word3dProperties();
    wordToCanvas->parent = canvas->handle;
    
    std::string line;

    std::ifstream myfile(filePath);
    if (myfile.is_open()) {
        GLfloat posy = 0;
        while (getline(myfile, line)) {
            
            posy -= 0.005;
            
            std::cout << line << '\n';
            
            std::vector<std::string> strs;
            boost::split(strs, line, boost::is_any_of("\t "));
            GLfloat posx = 0;
            bool first = true;
            for(std::string & wordstring : strs){
                std::cout << wordstring << std::endl;
                posx += 0.1;
                
                std::shared_ptr<Word> word = std::shared_ptr<Word>(new Word(wordToCanvas));
                word->next_line = first;
                first = false;
                word->handle = word->shared_from_this();
                word->name = wordstring;
                std::cout << word->parent->coords.x << std::endl;
                
                
//                std::cout << word->parent->coords.y << std::endl;
//                std::cout << word->parent->coords.z << std::endl;
//                exit(0);
//                word->coords.y = posy;
//                word->coords.x = posx;
                std::cout << "{" << word->dimension.width << "}" << std::endl;
                text->addElement(word);
                word->update();
                text->addElement(word);
            }
            
            std::cout << strs.size() << std::endl;
        }
//        exit(0);
        myfile.close();
    } else std::cout << "Unable to open file";

    boost::filesystem::path fe = filePath;

    std::cout << fe.extension().string();
//    exit(0);

    std::cout << "[common/filesystem/disk.cpp][disk_node::open] file name: " << filePath << std::endl;
}
