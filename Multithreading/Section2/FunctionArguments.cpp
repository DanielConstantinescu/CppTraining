#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

void work(int& count, mutex& mtx) {
    for(int i = 0; i < 1E6; i++) {
        mtx.lock();
        ++count;
        mtx.unlock();
    }
}

int main() {
    int count = 0;

    mutex mtx;


    thread t1(work, ref(count), ref(mtx));     // That's how we pass the arguments
    thread t2(work, ref(count), ref(mtx));

    t1.join();   // Waits here until t1 finish running the function
    t2.join();

    cout << count << endl;

    return 0;
}