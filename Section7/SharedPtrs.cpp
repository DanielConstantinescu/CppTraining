#include <iostream>
#include <memory>

class Project {
    std::string m_Name;
public:
    void SetName(const std::string &name) {
        m_Name = name;
    }

    void ShowProjectDetails()const {
        std::cout << "[Project Name]" << m_Name << std::endl;
    }
};

class Employee {
    //Project *m_pProject{};     // Raw pointer
    //std::unique_ptr<Project> m_pProject{};   // Unique pointer
    std::shared_ptr<Project> m_pProject{};
public:
    void SetProject(const std::shared_ptr<Project> &prj) {
        m_pProject = prj;                  
    }

    const std::shared_ptr<Project>& GetProject()const {
        return m_pProject;
    }
};

void ShowInfo(const std::shared_ptr<Employee> & emp) {
    std::cout << "Employee project details:";
    emp->GetProject()->ShowProjectDetails();
}

// Using a shared unique_ptr
// In this case we will get a Seg fault because after the first SetProject the resource from prj variable is moved
// and prj will be empty.
// Conclusion: we cannot share a unique_ptr because it does not allow copies and once is moved, cannot be used by other objects of type Employee

int main() {
    std::shared_ptr<Project> prj {new Project{}};
    prj->SetName("Video Decoder");
    
    std::shared_ptr<Employee> e1 {new Employee{}};
    e1->SetProject(prj);

    std::shared_ptr<Employee> e2 {new Employee{}};
    e2->SetProject(prj);

    std::shared_ptr<Employee> e3 {new Employee{}};
    e3->SetProject(prj);

    // How to check the internal counter of a shared pointer. Meant to be used only for debugging
    std::cout << "Reference count: " << prj.use_count() << std::endl;

    ShowInfo(e1);
    ShowInfo(e2);
    prj->ShowProjectDetails();

}