#include "Peon.hpp"

Peon::Peon(std::string name): Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &ref): Victim(ref) {
    if (this != &ref) {
        this->setName(ref.getName());
    }
}

Peon::~Peon(void) {
    std::cout << "Bleuark..." << std::endl;
}

void                Peon::getPolymorphed(void) const {
    std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}

/**
 * << operator overload
 */
std::ostream &operator<<(std::ostream &out, Peon const &ref) {
    out << ref.introduceString() << std::endl;
    return (out);
}