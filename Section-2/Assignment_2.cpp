#include <iostream>

void Add(int a, int b, int &result){
    result = a + b;
}

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp; 
}

void Factorial(int a, int &result){
    result = 1;

    for(int i=1;i <= a;i++) {
        result = result * i;
    }
}

int main(){
    int a = 5;
    int b = 6;
    int sum;

    std::cout << "NUmerele sunt " << a << " si " << b << std::endl;


    Add(a,b, sum);
    std::cout << "Add returneaza " << sum << std::endl;

    Swap(a, b);
    std::cout << "Numerele interschimbate sunt " << a << " si " << b << std::endl;

    int c = 6;
    int fact;
    Factorial(c,fact);

    std::cout << "Factorialul lui " << c << " este " << fact << std::endl;
    return 0;

}