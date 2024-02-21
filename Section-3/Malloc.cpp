#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Different types of memory access:
    - stack => allocated automatically for local variables
    - data section => allocated for global and static data
    - heap - allocated at runtime */


/* Functions for memory allocation:
    - malloc => allocate raw memory on the heap
    - calloc => allocates memory on the heap and initializes it to zero
    - realloc => allocates larger chunk of memory for an existing allocation
    - free => deallocates/releases the memory allocated trough the above functions */

void Malloc() {
    int *p = (int*)malloc(5 * sizeof(int));

    if (p == NULL) {
        printf("Failed to allocate memory\n");    // Condition to check if the memory was allocated
    }
    *p = 5;
    printf("%d\n", *p);
    free(p);
    //free(p);      // A second free would crash the program

    int *p1 = (int*)calloc(1, sizeof(int));   // Calloc initializes the memory to zero.
    *p1 = 6;
    printf("%d\n", *p1);
    free(p1);

}

void New() {
    int *p = new int(5);   // new allocates the memory but can also initialize the memory with the given value(5 in our case),
    *p = 6;                // a thing malloc and calloc cannot do
    std::cout << *p << std::endl;
    delete p;
    p = nullptr;           // even if we use delete, the pointer still points to that address so it would be a good idea to make it null pointer
}

// Allocation for  1D arrays (and string)
void NewArrays() {
    int *p = new int[5]{1,2,3,4,5}; // allocate memory for 5 integers ; If we also initialize it, it will be initialized in the memory as soon as it is
                                    // allocated
    //for (int i = 0; i < 5; ++i) {
     //   p[i] = i;
   // }

    delete []p;    // In this form we free memory for the whole array
}

void Strings() {
    char *p = new char[4];  // Every time we allocate memory for strings, allocate 1 extra byte for the end character
    strcpy(p, "C++");
    std::cout << p << std::endl;
    delete []p;
}

// Allocate memory for 2D arrays
void TwoD() {
    int *p1 = new int[3]; // first row
    int *p2 = new int[3]; // second row

    int **pData = new int *[2]; //Allocates memory for an 1D array of integer pointers
    pData[0] = p1;
    pData[1] = p2;

    pData[0][1] = 2; // Second element of the first row

    delete []p1; // Or delete []pData[0]
    delete []p2; // Or delete []pData[2]

    delete [] pData;
}

int main() {
    New();
    NewArrays();
    Strings();

    return 0;
}