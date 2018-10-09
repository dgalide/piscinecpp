#include "Form.hpp"

/**
 * Constructor / Destructor
 */
Form::Form(std::string name, int signGrade, int const execGrade): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {

    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form &ref): name(ref.getName()), isSigned(false), signGrade(ref.getSignGrade()), execGrade(ref.getExecGrade()) {}

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

/**
 * Exceptions
 */
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &e) {
    (void)e;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const &e) {
    (void)e;
    return *this;
}

const char          *Form::GradeTooHighException::what() const throw() {
    return ("Grade Not Low Enough.");
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &e) {
    (void)e;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &e) {
    (void)e;
    return *this;
}

const char          *Form::GradeTooLowException::what() const throw() {
    return ("Grade Not High Enough.");
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