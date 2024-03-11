#include <iostream>

int Add(int x, int y) {
    return x + y;
}

int main() {
    int x, y;
    std::cin >> x >> y;
    int result = Add(x, y);
    std::cout << "Result is " << result << std::endl;
}