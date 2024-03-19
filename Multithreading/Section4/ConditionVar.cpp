#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <condition_variable>

using namespace std;

int main() {

    condition_variable condition;
    mutex mtx;
    bool ready = false;

    thread t1([&](){
        this_thread::sleep_for(chrono::milliseconds(2000));

        cout << "t1 aquiring lock" << endl;
        unique_lock<mutex> lock(mtx);
        cout << "aquired lock" << endl;
        ready = true;
        lock.unlock();
        cout << "t1 released lock; notifying" << endl;
        condition.notify_one();
    });

    cout << "main thread aquiring lock" << endl;
    unique_lock<mutex> lock(mtx);

    cout << "main thread aquired lock" << endl;
    condition.wait(lock, [&](){return ready;});

    t1.join();

    cout << "main thread finished waiting" << endl;
    cout << "ready " << ready << endl;

    return 0;
}