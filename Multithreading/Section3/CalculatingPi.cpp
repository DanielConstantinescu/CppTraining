#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculate_pi(int terms) {
    double sum = 0.0;

    for(int i = 0; i < terms; i++) {
        double sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }

    return 4 * sum;
}

int main() {
    cout << setprecision(15) << calculate_pi(1E6) << endl;
    
    return 0;
}