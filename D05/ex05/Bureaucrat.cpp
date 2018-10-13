#include "Bureaucrat.hpp"

/**
 * Constructor / Destructor
 */
Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(Bureaucrat &ref): name(ref.getName()), grade(MIN_GRADE) {}

/**
 * Operator Overload
 */
void            Bureaucrat::operator-=(int const value) {
    this->decrement(value);
}

void            Bureaucrat::operator+=(int const value) {
    this->increment(value);
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
 * Getters
 */
int                 Bureaucrat::getGrade(void) const {
    return this->grade;
}

std::string         Bureaucrat::getName(void) const {
    return this->name;
}

/**
 * Method
 */
void                Bureaucrat::increment(int const value) {
    if (this->getGrade() - value <= MAX_GRADE) {
        throw Bureaucrat::GradeTooHighException();       
    } else {
        this->grade--;
    }
}

void                Bureaucrat::decrement(int const value) {
    if (this->getGrade() + value >= MIN_GRADE) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->grade++;
    }
}

void                Bureaucrat::signForm(Form &ref) {
    try {
        ref.beSigned(*this);
        std::cout << this->getName() << " signs " << ref.getName() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << this->getName() << " cannot sign " << ref.getName() << " for reason: " << e.what() << std::endl;
    }
}

void                Bureaucrat::executeForm(Form & form) {
    try {
        form.execute(*this);
        std::cout << this->getName() << " execute " << form.getName() << std::endl;
    } catch (Form::GradeTooLowException e) {
        std::cout << this->getName() << " cannot execute " << form.getName() << " for reason: " << e.what() << std::endl;
    }
}

/**
 * Stream operator
 */
std::ostream        &operator<<(std::ostream &stream, Bureaucrat &ref) {
    stream << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
    return stream;
}