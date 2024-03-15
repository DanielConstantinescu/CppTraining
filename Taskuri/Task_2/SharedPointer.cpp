// Task 2
#include <iostream>
#include <memory>

/***** Small example using a shared pointer and the advantages of sared pointers instead of unique pointer *****/
/*****                   CASE 3: SHARED POINTER                    *****/

/* A simple class that contains a string */
class Project {
    std::string m_Name;
public:
    void SetName(const std::string &name) {
        m_Name = name;
    }

    void ShowProjectDetails()const {
        std::cout << "[Project Name] " << m_Name << std::endl;
    }
};

/* A class that takes a pointer of a Project as attribute. We need a shared pointer because multiple employees can work on the same project. */
class Employee {
    std::shared_ptr<Project> m_pProject{};
public:
    void SetProject(const std::shared_ptr<Project> &prj) {
        m_pProject = prj;                  
    }

    const std::shared_ptr<Project>& GetProject()const {
        return m_pProject;
    }
};

/* Simple print function */
void ShowInfo(const std::shared_ptr<Employee> & emp) {
    std::cout << "Employee project details: ";
    emp->GetProject()->ShowProjectDetails();
}


/* Using a Unique Pointer would result in a Segmentation fault because, after the first call of SetProject, the resource from prj variable is moved
    and prj will be empty. When e2 will try to call SetProject, it will result in an error.*/
int main() {
    std::shared_ptr<Project> prj {new Project{}};
    prj->SetName("Video Decoder");
    
    /* For every constructor call, the internal counter increments. */
    std::shared_ptr<Employee> e1 {new Employee{}};
    e1->SetProject(prj);

    std::shared_ptr<Employee> e2 {new Employee{}};
    e2->SetProject(prj);

    std::shared_ptr<Employee> e3 {new Employee{}};
    e3->SetProject(prj);

    /* We can check the internal counter of a Shared Pointer with use_count(). Used mostly for debugging. */
    std::cout << "Reference count: " << prj.use_count() << std::endl;

    /* Display project for employees */
    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);

    /* Check if the Shared Pointer suffered modifications */
    prj->ShowProjectDetails();

    /* The resource will free itself so no need for additional calls.
        For every destructor call, the internal counter decrements and when it reaches 0, the resource is freed. */

    return 0;
}
