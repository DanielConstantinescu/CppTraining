#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

/* Prints data */
void print_data(vector<int>& data) {
    cout << "Data is: ";
    for (int elem : data) {
        cout << elem << " ";
    }
    cout << endl;
}

/* Adds a given element to the end of the data */
void push(vector<int>& data, int x) {
    cout << "Push " << x << endl;
    data.push_back(x);
}

/* Deletes the first element of the data */
void pop(vector<int>& data) {
    cout << "Pop " << data[0] << endl;
    data.erase(data.begin());
}


int main()
{
    vector<int> data;
    mutex mtx;
    condition_variable cond;

    /* Thread 1 takes care of the pop. */
    thread t1([&](){
        unique_lock<mutex> lock(mtx);
        cout << "Thread 1 aquires lock." << endl;
        cond.wait(lock, [&](){ return data.size() > 0; });  // Aquires the lock but then waits for the vector to be filled

        for(int i = 0; i < 3; i++) {
            pop(data);
            print_data(data);
        }

        cout << "Thread 1 releases lock." << endl;
        lock.unlock();      // Release lock and notify the other thread
        cond.notify_one();
    });

    thread t2([&](){
        unique_lock<mutex> lock(mtx);
        cout << "Thread 2 aquires lock." << endl;   // Aquire lock and fill the vector

        for(int i = 0; i < 4; i++) {
            push(data, i);
            print_data(data);
        }

        cout << "Thread 2 releases lock." << endl;   // Release lock and notify the other thread
        lock.unlock();
        cond.notify_one();
    });

    t1.join();   // Join the main thread
    t2.join();

    cout << endl;
    cout << "Final data" << endl;
    print_data(data);





}

