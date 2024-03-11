// Here we will discuss an issue that can be solved with weak pointers
//
// If we use only shared_ptr, the destuctors are not called so the memory is leaked. This happens because we are having two objects
// pointing each other. When we have shared pointers with circular references, the memory is not released.
// The counter will never become 0 even when the program returns because the two classes point each other.
//
// The solution is that one of the two pointers to be a weak pointer. This way one of the counters will not become 2 and will remain as 1, triggering
// delete at the return and this way, destroying the second one. Of course, we can also use 2 weak pointers.

#include <iostream>
#include <memory>

class Employee;     // To tell compiled Employee is a class that will be declared elsewhere

class Project {
public:
    std::shared_ptr<Employee> m_emp;

    Project() {
        std::cout << "Project()" << std::endl;
    }

    ~Project() {
        std::cout << "~Project()" << std::endl;
    }
};

class Employee {
public:
    std::weak_ptr<Project> m_prj;

    Employee() {
        std::cout << "Employee()" << std::endl;
    }

    ~Employee() {
        std::cout << "~Employee()" << std::endl;
    }
};

int main() {
    std::shared_ptr<Employee> emp {new Employee{}};
    std::shared_ptr<Project>prj {new Project{}};

    emp->m_prj = prj;
    prj->m_emp = emp;

    return 0;
}