#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
Form("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &ref):
Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade(), ref.getTarget())
{}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void            PresidentialPardonForm::action(void) {
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}