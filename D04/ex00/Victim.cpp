#include "Victim.hpp"

Victim::Victim(std::string name): name(name) {
    std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &ref) {
    if (this != &ref) {
        this->setName(ref.getName());
    }
}

Victim::~Victim(void) {
    std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
}

/**
 * Method
 */

std::string        Victim::introduceString(void) const {
    std::ostringstream ss;
    ss << "I am ";
    ss << this->getName();
    ss << " and I like otters !";
    return ss.str();
}

void                Victim::getPolymorphed(void) const {
    std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

void                Victim::introduceYourself(void) const {
    std::cout << this->introduceString() << std::endl;
}

/**
 * << operator overload
 */
std::ostream &operator<<(std::ostream &out, Victim const &ref) {
    out << ref.introduceString() << std::endl;
    return (out);
}

/**
 * Getters
 */
std::string             Victim::getName(void) const {
    return this->name;
}

/**
 * Setters
 */

void                    Victim::setName(std::string name) {
    this->name = name;
}