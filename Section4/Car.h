#pragma once            //This pragma cause the current header file to be included only once in a single compilation

class Car {
private:
    float fuel { 0 };      // BY giving a value between {} we use Non-Static Data Member Initialization
    float speed { 0 };
    int passengers { 0 };

   /*
    int arr[5] = { 1,2,3 };  // We can default initialize arrays
    char *p{};               // And even pointers. In this case the pointer is default initialized to null
   */
   static int totalCount;    // Declaration of the static variable
public:
    Car();                           // Default constructor
    Car(float amount);               // Parameterized constructor
    Car(float amount, int passengers);
    ~Car();                          // Destructor

    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);
    void Dashboard() const;          // We can qualify Dashboard as const because it does not modify the state of the object
    static void ShowCount();
};
