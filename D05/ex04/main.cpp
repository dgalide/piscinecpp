#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

class Form;
class Bureaucrat;

int main(void)
{

        Intern          *idiotOne =  new Intern();
        Bureaucrat      *hermes = new Bureaucrat("Hermes Conrad", 150);
        Bureaucrat      *bob = new Bureaucrat("Bobby Bobson", 150);
        OfficeBlock ob;
        ob.setIntern(idiotOne);
        ob.setSigningBureaucrat(bob);
        ob.setExecutingBureaucrat(hermes);

        try {
                ob.doBureaucracy("president", "Pigley");
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        return 0;
}