#ifndef HANDLE
#define HANDLE
#include <vector>
#include <memory>

class virtual_handle :
public std::enable_shared_from_this<virtual_handle> {
public:

    virtual ~virtual_handle() {
    }
};

template <class T>
class Handle : virtual public virtual_handle {
public:

    std::shared_ptr<T> shared_from_this() {
        return std::dynamic_pointer_cast<T>(virtual_handle::shared_from_this());
    }
};





#endif