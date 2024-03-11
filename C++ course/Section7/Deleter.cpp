// In some cases we would like to manage a pointer who points to a resource that cannot be deleted using delete;

#include <iostream>
#include <memory>

struct Free {                    // We will define as a function object. We use a structure to make sure everything is public, but we can also use class
    void operator()(int *p) {    // The second argument must be the type we want to release.
        free(p);
        std::cout << "pointer freed" << std::endl;
    }
};

void  MallocFree(int* p) {
    free(p);
    std::cout << "pointer freed" << std::endl;
}

// Unique pointer case
void UniquePtrDeleters() {

   // std::unique_ptr<int, Free> p {(int*) malloc(4), Free{}};  // We have no certitude the memory is freed because, for example, for malloc we must call free and
                                                              // for new we must call delete
                                                              // We must specify the type of the deleter and an object of the deleter class

    std::unique_ptr<int, void (*)(int *)> p {(int*) malloc(4), MallocFree};  // Here the deleter is a function

    *p = 100;

    std::cout << *p << std::endl;
}

// Shared pointer case
void SharedPtrDeleters() {
    std::shared_ptr<int> p {(int*) malloc(4), Free{}};

    //std::shared_ptr<int> p {(int*) malloc(4), MallocFree};  // For shared pointer we don't have to specify the type of the deleter as argument

    *p = 100;

    std::cout << *p << std::endl;
}

int main() {
    SharedPtrDeleters();
}


