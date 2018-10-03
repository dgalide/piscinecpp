#include "Fixed.hpp"

const int Fixed::nbFractional = 8;

// Constructor
Fixed::Fixed(void): value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(Fixed const &ref): value(ref.value) {
    std::cout << "Copy constructor called" << std::endl;
}

// assignation operator overload '='
Fixed& Fixed::operator=(const Fixed&ref) {
    if (this != &ref) {
        std::cout << "Assignation operator called" << std::endl;

        this->value = ref.value;
    }

    return *this;
}

// Destructor
Fixed::~Fixed(void) {}

void        Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

int         Fixed::getRawBits(void) {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}