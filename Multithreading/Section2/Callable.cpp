#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

class App {
private:
    int count;
    mutex mtx;
public:
    void operator ()() {
        for(int i = 0; i < 1E6; i++) {
            lock_guard<mutex> guard(mtx);
            ++count;
        }
    }

    int getCount() {
        return count;
    }
};


int main() {
    App app;

    thread t1(ref(app));   
    thread t2(ref(app));

    t1.join();   // Waits here until t1 finish running the function
    t2.join();

    cout << app.getCount() << endl;

    return 0;
}