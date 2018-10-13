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
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &e) {
    (void)e;
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &e) {
    (void)e;
    return *this;
}

const char          *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade Not Low Enough.");
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &e) {
    (void)e;
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &e) {
    (void)e;
    return *this;
}

const char          *Bureaucrat::GradeTooLowException::what() const throw() {
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

/**
 * Stream operator
 */
std::ostream        &operator<<(std::ostream &stream, Bureaucrat &ref) {
    stream << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
    return stream;
}