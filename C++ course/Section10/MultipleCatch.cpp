#include <iostream>
#include <limits>

int ProcessRecords(int count) {
    if (count < 10)
        throw std::out_of_range("Count should be greater than 10");

    int *p = new int[count];
    int *pArray = (int*)malloc(count * sizeof(int));
    if (pArray == nullptr) {
        std::cout << "Failed to allocate memory" << std::endl;
        return -1;
    }

    // Process the records
    for(int i = 0; i < count; ++i) {
        pArray[i] = i;
    }
    free(pArray);
}

int main() {
    try {
        ProcessRecords(std::numeric_limits<int>::max());
    }
    catch (std::runtime_error &ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::out_of_range &ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc &ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}