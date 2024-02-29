#include <iostream>

#define __FUNCSIG__ __PRETTY_FUNCTION__

union Test {
    int x;
    char ch;
    double d;   // Now the size of the union is no longer int, it is double

    Test(): ch{'a'} {                // In the contructor we can initialize only one attribute, but not 2 or more. In this case we can initialize either x or ch.
        std::cout << __FUNCSIG__ << std::endl;
    }

    ~Test() {
        std::cout << __FUNCSIG__ << std::endl;
    }
};

struct A {
	A() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~A() {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A(const A& other) {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A(A&& other) noexcept{
		std::cout << __FUNCSIG__ << std::endl;
	}

	A& operator=(const A& other) {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}

	A& operator=(A&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}
};
struct B {

	B() {
		std::cout << __FUNCSIG__ << std::endl;

	}
	~B() {
		std::cout << __FUNCSIG__ << std::endl;

	}

	B(const B& other) {
		std::cout << __FUNCSIG__ << std::endl ;
	}

	B(B&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl ;
	}

	B& operator=(const B& other) {
		std::cout << __FUNCSIG__ << std::endl ;
		if (this == &other)
			return *this;
		return *this;
	}

	B& operator=(B&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl ;
		if (this == &other)
			return *this;
		return *this;
	}
	virtual void Foo(){}
	
};


// Let's see what happens if we stored an user-defined type in an union

union UDT {         // Because structures A and B have user-defined constructors and destructors, we must also create them in the union
    A a;
    B b;
    std::string s;

    UDT() {

    }

    ~UDT() {

    }
};

int main() {

    std::cout << sizeof(Test) << std::endl;

    Test t;
    std::cout << t.ch << std::endl;

    t.x = 1000;    // At this moment, x is the active member. There is no way to know which is the active member, so if we try to read ch
                   // we will get an undefined result. This is one big disadvantage of union

    std::cout <<t.ch << std::endl;  // returns undefined and print something strange

    // Unions with user defined types
    std::cout << "Unions with user-defined types" << std::endl;

    UDT udt;    // If we compile here, we notice that the constructors of A and B are not called

    //udt.s = "Hello World";  // This returns an error because s is undefined

    // The only way to initialize a user-defined type inside in a union is trough the placement new operator.
    // Placement new is another form of new, it initialize the memory, but do not allocate.

    new(&udt.s) std::string{"Hello World"};   // this is how we should do it

    new (&udt.a) A{};  // this will call the default constructor of A

    udt.a.~A();        // We have to manually invoke the destructor

    return 0;
}