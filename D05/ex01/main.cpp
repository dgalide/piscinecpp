#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form;
class Bureaucrat;

int main(void)
{
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("alice", 150);
    Form        f1("form 1", 1, 10);
    Form        f2("form 1", 150, 10);

    alice.signForm(f2);
    alice.signForm(f1);

    bob.signForm(f1);
    bob.signForm(f1);
    return 0;
}