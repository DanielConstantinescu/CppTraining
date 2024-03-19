#include <iostream>
#include <thread>
#include <cmath>
#include <future>
#include <iomanip>

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
    packaged_task<double(int)> task1(calculate_pi);

    future<double> future1 = task1.get_future();

    thread t1(move(task1), 0);   // Cannot copy packaged tasks so we have to use either ref() if we will need it in the future or move()

    try {
        double result = future1.get();
        cout << setprecision(15) << result << endl;
    }
    catch (const std::exception &e) {
        cout << "ERROR " << e.what() << endl;
    }


    t1.join();


    return 0;
}