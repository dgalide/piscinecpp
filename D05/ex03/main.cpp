#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

class Form;
class Bureaucrat;

int main(void)
{

    Intern  i;
    Form    *f;
    Bureaucrat b("baby", 1);

    f = i.makeForm("president", "zaphod");

    b.signForm(*f);
    b.executeForm(*f);
    
    return 0;
}