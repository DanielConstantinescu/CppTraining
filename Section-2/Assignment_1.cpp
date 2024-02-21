#include <iostream>

int Add(int *a, int *b){
    return *a + *b;
}

void AddVal(int *a, int *b, int *result){
    *result = *a + *b;
}

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void Factorial(int *a, int *result){
    *result = 1;

    for(int i=1;i <= *a;i++) {
        *result = *result * i;
    }
}

int main(){
    int a = 5;
    int b = 6;
    int sum, sum1;

    std::cout << "NUmerele sunt " << a << " si " << b << std::endl;


    sum = Add(&a,&b);
    std::cout << "Add returneaza " << sum << std::endl;

    AddVal(&a, &b, &sum1);
    std::cout << "AddVal returneaza " << sum1 << std::endl;

    Swap(&a, &b);
    std::cout << "Numerele interschimbate sunt " << a << " si " << b << std::endl;

    int c = 6;
    int fact;
    Factorial(&c,&fact);

    std::cout << "Factorialul lui " << c << " este " << fact << std::endl;
    

}