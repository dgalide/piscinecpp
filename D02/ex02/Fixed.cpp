#include "Fixed.hpp"

const int Fixed::nbFractional = 8;

// Constructor
Fixed::Fixed(void): value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value): value(value << nbFractional) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value) {
    // std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << nbFractional));
}

// copy constructor
Fixed::Fixed(Fixed const &ref): value(ref.value) {
    *this = ref;
    // std::cout << "Copy constructor called" << std::endl;
}

// assignation operator overload '='
Fixed& Fixed::operator=(Fixed const &ref) {
    if (this != &ref) {
        // std::cout << "Assignation operator called" << std::endl;

        this->value = ref.getRawBits();
    }

    return *this;
}

const Fixed& Fixed::min(Fixed const &r1, Fixed const &r2) {
    return (r2.operator<(r1) ? r2 : r1);
}

const Fixed& Fixed::max(Fixed const &r1, Fixed const &r2) {
    return (r2.operator<(r1) ? r1 : r2);
}

bool    Fixed::operator<(Fixed const &ref) const {
    if (this != &ref) {
        return (this->value < ref.getRawBits() ? true : false);
    }
    return false;
}

bool    Fixed::operator<=(Fixed const &ref) const {
    if (this != &ref) {
        return (this->value <= ref.getRawBits() ? true : false);
    }
    return false;
}

bool    Fixed::operator>=(Fixed const &ref) const {
    if (this != &ref) {
        return (this->value >= ref.getRawBits() ? true : false);
    }
    return false;
}

bool    Fixed::operator==(Fixed const &ref) const {
    if (this != &ref) {
        return (this->value == ref.getRawBits() ? true : false);
    }
    return true;
}

bool    Fixed::operator!=(Fixed const &ref) const {
    if (this != &ref) {
        return (this->value != ref.getRawBits() ? true : false);
    }
    return false;
}

bool    Fixed::operator>(Fixed const &ref) const {
    if (this != &ref) {
        return (this->value > ref.getRawBits() ? true : false);
    }
    return false;
}

Fixed   Fixed::operator+(Fixed const &ref) {
    Fixed f;

    f.setRawBits((this->value + ref.getRawBits()));

    return f;
}

Fixed   Fixed::operator-(Fixed const &ref) {
    Fixed f;

    f.setRawBits((this->value - ref.getRawBits()));

    return f;
}

Fixed   Fixed::operator*(Fixed const &ref) {
    Fixed f;

    f.setRawBits((this->value * ref.getRawBits()));
    f.value = f.toFloat();

    return f;
}

Fixed   Fixed::operator/(Fixed const &ref) {
    Fixed f;
    f.setRawBits((this->value - ref.getRawBits()));
    f.value = f.toFloat();

    return f;
}

Fixed   Fixed::operator++(void) {
    this->value += 1;
    return *this;
}

Fixed   Fixed::operator--(void) {
    this->value -= 1;
    return *this;
}

Fixed   Fixed::operator++(int) {
    Fixed f(*this);

    this->operator++();
    return f;
}

Fixed   Fixed::operator--(int) {
    this->operator--();
    return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &val) {
    out << val.toFloat();
    return (out);
}

// Destructor
Fixed::~Fixed(void) {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const {
    return ((int)this->value >> nbFractional);
}

float Fixed::toFloat(void) const {
    return ((float)this->value / (1 << nbFractional));
}

void        Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

int         Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}