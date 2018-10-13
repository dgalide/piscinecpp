#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void): intern(nullptr), signingBureaucrat(nullptr), executingBureaucrat(nullptr) {}

OfficeBlock::~OfficeBlock(void) {}

void        OfficeBlock::setIntern(Intern *intern) {
    this->intern = intern;
}

void        OfficeBlock::setSigningBureaucrat(Bureaucrat *b) {
    this->signingBureaucrat = b;
}

void        OfficeBlock::setExecutingBureaucrat(Bureaucrat *b) {
    this->executingBureaucrat = b;
}

void        OfficeBlock::doBureaucracy(std::string formName, std::string target) {
    if (!this->isTeamComplete()) {
        throw OfficeBlock::TeamNotComplete();
    }
    Form    *f = this->intern->makeForm(formName, target);

    this->signingBureaucrat->signForm(*f);
    this->executingBureaucrat->executeForm(*f);
}

bool        OfficeBlock::isTeamComplete(void) {
    return !(!this->intern || !this->signingBureaucrat || !this->executingBureaucrat);
}

/**
 * Exceptions
 */

OfficeBlock::TeamNotComplete::~TeamNotComplete(void) throw() {}
OfficeBlock::TeamNotComplete::TeamNotComplete(void) {}
OfficeBlock::TeamNotComplete::TeamNotComplete(TeamNotComplete const &e) {
    (void)e;
}

OfficeBlock::TeamNotComplete &OfficeBlock::TeamNotComplete::operator=(TeamNotComplete const &e) {
    (void)e;
    return *this;
}

const char          *OfficeBlock::TeamNotComplete::what() const throw() {
    return ("The Team isn't Complete");
}