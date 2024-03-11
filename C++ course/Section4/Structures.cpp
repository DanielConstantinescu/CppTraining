#include <iostream>

struct Point {
    int x;
    int y;
};

/*
void DrawLine(int x1, int y1, int x2, int y2) {    // In this kind of definition, the arguments are not very clear.  
                                                   // Would be clearer if the arguments would be 2 points instead of 4 coordinates
}
*/

void DrawLine (Point start, Point end) {
    std::cout << start.x << std::endl;

}

int main() {


    return 0;
}