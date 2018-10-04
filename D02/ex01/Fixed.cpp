#include "Fixed.hpp"

const int Fixed::nbFractional = 8;

// Constructor
Fixed::Fixed(void): value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value): value(value << nbFractional) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << nbFractional));
}

// copy constructor
Fixed::Fixed(Fixed const &ref): value(ref.value) {
    *this = ref;
    std::cout << "Copy constructor called" << std::endl;
}

// assignation operator overload '='
Fixed& Fixed::operator=(Fixed const &ref) {
    if (this != &ref) {
        std::cout << "Assignation operator called" << std::endl;

        this->value = ref.getRawBits();
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &val) {
    out << val.toFloat();
    return (out);
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const {
    return ((int)this->value >> nbFractional);
}

float Fixed::toFloat(void) const {
    return ((float)this->value / (1 << nbFractional));
}

void        Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

int         Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}