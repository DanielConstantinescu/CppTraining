#include <iostream>
#include <limits>

int ProcessRecords(int count) {
    int *pArray = (int*)malloc(count * sizeof(int));
    if (pArray == nullptr) {
        std::cout << "Failed to allocate memory" << std::endl;
        return -1;
    }
    for(int i = 0; i < count; ++i) {
        pArray[i] = i;
    }
    free(pArray);
    return 0;
}

int main() {
    try {
        ProcessRecords(std::numeric_limits<int>::max());
    }
    catch (std::runtime_error &ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}