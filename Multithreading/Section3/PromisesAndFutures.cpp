#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <future>
#include <exception>

using namespace std;

double calculate_pi(int terms) {
    double sum = 0.0;

    if (terms < 1) {
        throw runtime_error("Terms cannot be less than 1");
    }


    for(int i = 0; i < terms; i++) {
        double sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }

    return 4 * sum;
}

int main() {
    promise<double> promise;     // We use promise to get the value from a thread

    auto do_calculation = [&](int terms){
        try {
            auto result = calculate_pi(terms);
            promise.set_value(result);   // set the value in the promise

        } catch (const std::exception &e) {
            promise.set_exception(current_exception());   // this is how you set an exception in a promise
        }
    };

    thread t1(do_calculation, 1E6);
    t1.join();

    future<double> future = promise.get_future(); // we use future to get the value from the promise

    try {
        cout << setprecision(15) << future.get() << endl;
    } catch(const std::exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}