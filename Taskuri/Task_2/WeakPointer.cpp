#include <iostream>
#include <memory>

/*****    Special situation to show the utility of weak pointers    *****/
/*****                    CASE 4: WEAK POINTER                    *****/

/* We have to classes that declare a pointer which points to the other one, like a circle. */
/*** Situation 1: For start, we will use Shared Pointer in both classes 
    
   Conclusion: We notice that no destructor is called. That's  because objects are interdependent.

   Output: Employee()
           Project()
           Employee()
           Project()
    
***/

/*** Situation 2: We try to delete one of the objects manualy.
 
     Conclusion: The destructors are called but due to the cycle aspect, we encounter the error "free(): double free detected in tcache 2"

     Output: Employee()
             Project()
             ~Project()
             Employee()
             Project()
             ~Employee()
             ~Project()
             ~Project()
             ~Employee()
             free(): double free detected in tcache 2
             Aborted (core dumped)
***/

/*** Situation 3: We replace the Shared Pointer from Employee class with a weak pointer 
 
     Conclusion: Due to the non-owning aspect of the weak pointer. This way it does not increment the counter of the other one and the cycle is broken

     Output: Employee()
             Project()
             Employee()
             Project()
             ~Project()
             ~Employee()
             ~Project()
             ~Employee()
***/

/* Let the compiler know class Employee will be implemented somewhere else in the file. */
class Employee;

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
    std::shared_ptr<Employee> emp1 {new Employee{}};
    std::shared_ptr<Project>prj1 {new Project{}};

    emp1->m_prj = prj1;
    prj1->m_emp = emp1;

    /* We try to delete one of the objects manually. */
    //delete prj1.get();

    std::shared_ptr<Employee>emp2 {new Employee{}};
    std::shared_ptr<Project>prj2 {new Project{}};

    emp2->m_prj = prj2;
    prj2->m_emp = emp2;

    return 0;
}