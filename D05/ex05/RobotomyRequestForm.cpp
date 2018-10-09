#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
Form("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &ref):
Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade(), ref.getTarget())
{}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void            RobotomyRequestForm::action(void) {
    srand(time(NULL));

    if (rand() % 2) {
        std::cout << this->getName() << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << this->getName() << " has not been robotomized successfully" << std::endl;
    }
}