
#include <string>
//std::string build_path(int parent_id, std::string project_root) {
//    std::string path = project_root;
//    std::string compound;
//    while (parent_id) {
//        compound = DiskEntities[parent_id].name + "/" + compound;
//        parent_id = DiskEntities[parent_id].parent_id;
//    }
//    return path + "/" + compound;
//}
//
//int find_parent(int parent_id) {
//    if (itr->path().parent_path().string() + "/" == build_path(parent_id)) {
//        return parent_id;
//    }
//    while (itr->path().parent_path().string() + "/" != build_path(parent_id)) {
//        parent_id = DiskEntities[parent_id].parent_id;
//    }
//    return parent_id;
//}