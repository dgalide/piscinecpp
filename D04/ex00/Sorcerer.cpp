#include "Sorcerer.hpp"
#include <sstream>

Sorcerer::Sorcerer(std::string name, std::string title): name(name), title(title) {
    std::cout << name << ", " << title << " is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &ref) {
    if (this != &ref) {
        this->setName(ref.getName());
        this->setTitle(ref.getTitle());
    }
}

Sorcerer::~Sorcerer(void) {
    std::cout << this->getName() << ", " << this->getTitle() << " is dead. Consequences will never be the same !" << std::endl;
}

/**
 * Method
 */

std::string        Sorcerer::introduceString(void) const {
    std::ostringstream ss;
    ss << "I am ";
    ss << this->getName();
    ss << ", ";
    ss << this->getTitle();
    ss << " and I like ponies !";
    return ss.str();
}

void                Sorcerer::polymorph(Victim const &v) const {
    v.getPolymorphed();
}

void                Sorcerer::introduceYourself(void) const {
    std::cout << this->introduceString() << std::endl;
}

std::ostream &operator<<(std::ostream &out, Sorcerer const &ref) {
    out << ref.introduceString() << std::endl;
    return (out);
}

/**
 * Getters
 */
std::string             Sorcerer::getName(void) const {
    return this->name;
}

std::string             Sorcerer::getTitle(void) const {
    return this->title;
}

/**
 * Setters
 */

void                    Sorcerer::setName(std::string name) {
    this->name = name;
}

void                    Sorcerer::setTitle(std::string title) {
    this->title = title;
}