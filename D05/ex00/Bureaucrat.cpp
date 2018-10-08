#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name): name(name), grade(MIN_GRADE) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(Bureaucrat &ref): name(ref.getName()), grade(MIN_GRADE) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &ref) {
    *this = ref;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &ref) {
    *this = ref;
}

const char          *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is at min already...");
}

const char          *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is at max already...");
}

int                 Bureaucrat::getGrade(void) const {
    return this->grade;
}

std::string         Bureaucrat::getName(void) const {
    return this->name;
}

void                Bureaucrat::increment(void) {
    if (this->getGrade() == MAX_GRADE) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        this->grade--;
    }
}

void                Bureaucrat::decrement(void) {
    if (this->getGrade() == MIN_GRADE) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->grade++;
    }
}

std::ostream        &operator<<(std::ostream &stream, Bureaucrat &ref) {
    stream << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
    return stream;
}