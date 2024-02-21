#include <iostream>

namespace Avg {
    float Calculate(float x, float y) {
        return (x+y)/2;
    }
}

namespace Basic {
    float Calculate(float x, float y) {
        return x + y;
    }
}

int main() {
    // This is not correct because the compiler can still not choose between these 2, that's why it would be better to use declarativ names
    
    /*using namespace Avg;                                               
    std::cout << Calculate(3.9f, 8.2f) << std::endl;

    using namespace Basic;
    std::cout << Calculate(3.9f, 8.2f) << std::endl;*/     

    // Using declarative names
    using namespace std;
    cout << "Using Avg: " << Avg::Calculate(3.9f, 8.2f) << endl;
    cout << "Using Basic: "<< Basic::Calculate(3.9f, 8.2f) << endl;

    return 0;
}