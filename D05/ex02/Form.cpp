#include "Form.hpp"

/**
 * Constructor / Destructor
 */
Form::Form(std::string name, int signGrade, int const execGrade, std::string target): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade),target(target) {

    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (signGrade > MIN_GRADE || execGrade > MAX_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form &ref): name(ref.getName()), isSigned(false), signGrade(ref.getSignGrade()), execGrade(ref.getExecGrade()), target(ref.getTarget()) {}

Form::~Form(void) {}
/**
 * Getters
 */
int                 Form::getSignGrade(void) const {
    return this->signGrade;
}

int                 Form::getExecGrade(void) const {
    return this->execGrade;
}

std::string         Form::getName(void) const {
    return this->name;
}

bool                Form::getSigned(void) const {
    return this->isSigned;
}

std::string         Form::getTarget(void) const {
    return this->target;
}

/**
 * Exceptions
 */
const char          *Form::GradeTooHighException::what() const throw() {
    return ("Grade Not High Enough ..");
}

const char          *Form::GradeTooLowException::what() const throw() {
    return ("Grade Not Low Enough ..");
}

/**
 * Stream Operator
 */
std::ostream        &operator<<(std::ostream &stream, Form &ref) {
    stream << ref.getName()
    << (ref.getSigned() ? " is signed. Sign Grade is equal to " : " is not signed. Sign Grade is equal to ")
    << std::to_string(ref.getSignGrade())
    << " and an execution grade equal to "
    << std::to_string(ref.getExecGrade())
    << std::endl;
    return stream;
}

/**
 * Method
 */
void                Form::beSigned(Bureaucrat &ref) {
    if (ref.getGrade() > this->getSignGrade()) {
        throw Form::GradeTooLowException();
    } else {
        this->isSigned = true;
    }
}