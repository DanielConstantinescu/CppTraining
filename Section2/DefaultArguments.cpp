#include <iostream>

void CreateWindow(const char * title, int x = -1, int y = -1, int width = -2, int heigh = -2) { //We can set default values for arguments by writtin it with an =
    using namespace std;
    cout << "Title : " << title << endl;
    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
    cout << "Width : " << width << endl;
    cout << "Heigh : " << heigh << endl;
}

int main() {

    CreateWindow("Notepad", 150, 200, 500 ,600);
    CreateWindow("Notepad++", 100, 200);
}