#include <iostream>

void Print(int count, char ch) {
    using namespace std;
    for (int i = 0;i < count; ++i) {
        cout << ch;
    }
    cout << endl;
}

void EndMessage() {
    using namespace std;
    cout << "End of program" << endl;
}

int main() {
    atexit(EndMessage);    // atexit is always call at the end of the program, no matter where it is written
    Print(5, '#');
    void(*pfn) (int, char) = Print; // Create pointer to function

    (*pfn)(8, '@');
    (*pfn)(5,'+');

    std::cout << "End of main" << std::endl;
    return 0;
}

