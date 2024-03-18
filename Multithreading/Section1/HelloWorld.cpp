#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void work() {
    for (int i = 0; i < 10; i++) {
        this_thread::sleep_for(chrono::milliseconds(500)); // wait half a second
        cout << "Loop " << i << endl;
    }
}

int main() {
    thread t1(work);
    thread t2(work);

    t1.join();   // Waits here until t1 finish running the function
    t2.join();

    return 0;
}