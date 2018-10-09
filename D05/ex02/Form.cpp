#include "Form.hpp"

/**
 * Constructor / Destructor
 */
Form::Form(std::string name, int signGrade, int const execGrade, std::string target): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade),target(target) {

    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE) {
        std::cout << "TOO HIGH -> " << std::to_string(signGrade) << ", " << std::to_string(execGrade) << std::endl;
        throw Bureaucrat::GradeTooHighException();
    }
    else if (signGrade > MIN_GRADE || execGrade > MIN_GRADE) {
        std::cout << "TOO LOW -> " << std::to_string(signGrade) << ", " << std::to_string(execGrade) << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

Form::Form(Form &ref): name(ref.getName()), isSigned(false), signGrade(ref.getSignGrade()), execGrade(ref.getExecGrade()), target(ref.getTarget()) {}

Form        &Form::operator=(Form &ref) {
    if (this != &ref) {
        *this = ref;
    }
    return *this;
}

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

Form::alreadySignedException::~alreadySignedException(void) throw() {}
Form::alreadySignedException::alreadySignedException(void) {}
Form::alreadySignedException::alreadySignedException(alreadySignedException const &e) {
    (void)e;
}

Form::alreadySignedException &Form::alreadySignedException::operator=(alreadySignedException const &e) {
    (void)e;
    return *this;
}

const char          *Form::alreadySignedException::what() const throw() {
    return ("Form Has Been Signed Already.");
}


Form::notSignedException::~notSignedException(void) throw() {}
Form::notSignedException::notSignedException(void) {}
Form::notSignedException::notSignedException(notSignedException const &e) {
    (void)e;
}

Form::notSignedException &Form::notSignedException::operator=(notSignedException const &e) {
    (void)e;
    return *this;
}

const char          *Form::notSignedException::what() const throw() {
    return ("Form Not Signed Yet.");
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
    if (!this->isEnoughToSign(ref)) {
        throw Form::GradeTooLowException();
    } else {
        this->isSigned = true;
    }
}

bool                Form::isEnoughToSign(Bureaucrat &b) {
    return b.getGrade() <= this->getSignGrade();
}

bool                Form::isEnoughToExec(Bureaucrat &b) {
    return b.getGrade() <= this->getExecGrade();
}

void                Form::execute(Bureaucrat &b) {
    if (this->isSigned && this->isEnoughToExec(b)) {
        this->action();
    } else if (!this->isSigned) {
        throw Form::notSignedException();
    } else {
        throw Form::GradeTooLowException();
    }
}