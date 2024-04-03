#include <iostream>
#include <limits>
#include <memory>
#include <vector>
#include <random>

class Test {
public:
    Test() { std::cout << "Test(): Aquire resources" << std::endl; }
    ~Test() { std::cout << "~Test():Release resources" << std::endl; }
};

int ProcessRecords(int count) {
    std::unique_ptr<Test> t(new Test);
    if (count < 10)
        throw std::out_of_range("Count should be greater than 10");

    std::vector<int> p;
    p.reserve(count);
    std::vector<int> pArray;
    pArray.reserve(count);

    // Process the records
    for(int i = 0; i < count; ++i) {
        pArray.push_back(i);
    }

    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    for(int i = 0; i < count; ++i) {
        try {
            std::cout << "Processing record # : " << i << " ";
            if(!dist(eng))
                throw std::runtime_error("Could not process the record");
        }
        catch(std::runtime_error &ex) {
            std::cout << "[ERROR " << ex.what() << "]" << std::endl;
        }
    }
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