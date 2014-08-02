#ifndef PROJECT
#define PROJECT
#include <boost/filesystem.hpp>
#include <memory>
#include <common/filesystem/disk.hpp>
#include <common/space/scene.hpp>

#include <common/environment/world.hpp>
extern World * world;

class Directory {
public:
    Directory(std::string);
    ArraysInstanced scene;
    void update();
private:
//    void process_directory(std::shared_ptr<disk_node> directory);
    std::shared_ptr<disk_node> root_directory;
    std::shared_ptr<disk_node> current_parent;
    boost::filesystem::path path;
    boost::filesystem::recursive_directory_iterator current_iteration;
    std::string build_path(std::shared_ptr<disk_node>);
    void find_parent();
    void recurse(std::shared_ptr<disk_node>);
};
#endif