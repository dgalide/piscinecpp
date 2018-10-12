#include "span.hpp"

Span::Span(unsigned int n): n(n) {
    this->v = new std::vector<int>();
}

Span::Span(Span const &ref): n(ref.getN()) {
    this->v = new std::vector<int>();
}

Span::~Span(void) {}

unsigned int        Span::getN(void) const {
    return this->n;
}

int         Span::shortestSpan(void) {
    int shortest;

    if (this->v->size() == 1) {
        throw Span::NotEnoughData();
    } else if (this->v->size() == 0) {
        throw Span::ArrayEmpty();
    }
    shortest = this->getSpan(this->v->at(0), this->v->at(1));
    for (std::vector<int>::iterator it1 = this->v->begin(); it1 != this->v->end();it1++) {
        for (std::vector<int>::iterator it2 = this->v->begin(); it2 != this->v->end();it2++) {
            if (std::distance(this->v->begin(), it1) != std::distance(this->v->begin(), it2)) {
                if (this->getSpan(*it1, *it2) < shortest) {
                    shortest = this->getSpan(*it1, *it2);
                }
            }
        }
    }
    return shortest;
}

int         Span::getSpan(int a, int b) {
    int     out = a - b;

    return (out < 0 ? out * -1: out);
}

int         Span::longestSpan(void) {
    int longest;

    if (this->v->size() == 1) {
        throw Span::NotEnoughData();
    } else if (this->v->size() == 0) {
        throw Span::ArrayEmpty();
    }
    longest = this->getSpan(this->v->at(0), this->v->at(1));
    for (std::vector<int>::iterator it1 = this->v->begin(); it1 != this->v->end();it1++) {
        for (std::vector<int>::iterator it2 = this->v->begin(); it2 != this->v->end();it2++) {
            if (std::distance(this->v->begin(), it1) != std::distance(this->v->begin(), it2)) {
                if (this->getSpan(*it1, *it2) > longest) {
                    longest = this->getSpan(*it1, *it2);
                }
            }
        }
    }
    return longest;
}

void        Span::addNumber(int a) {
    if (this->v->size() < this->n) {
        this->v->push_back(a);
    } else {
        throw Span::ArrayFull();
    }
}

/**
 * Exceptions
 */
Span::ArrayFull::~ArrayFull(void) throw() {}
Span::ArrayFull::ArrayFull(void) {}
Span::ArrayFull::ArrayFull(ArrayFull const &e) {
    (void)e;
}

Span::ArrayFull &Span::ArrayFull::operator=(ArrayFull const &e) {
    (void)e;
    return *this;
}

const char          *Span::ArrayFull::what() const throw() {
    return ("Array is Full already");
}

/**
 * Exceptions
 */
Span::ArrayEmpty::~ArrayEmpty(void) throw() {}
Span::ArrayEmpty::ArrayEmpty(void) {}
Span::ArrayEmpty::ArrayEmpty(ArrayEmpty const &e) {
    (void)e;
}

Span::ArrayEmpty &Span::ArrayEmpty::operator=(ArrayEmpty const &e) {
    (void)e;
    return *this;
}

const char          *Span::ArrayEmpty::what() const throw() {
    return ("Can't perfom the request on empty array.");
}

/**
 * Exceptions
 */
Span::NotEnoughData::~NotEnoughData(void) throw() {}
Span::NotEnoughData::NotEnoughData(void) {}
Span::NotEnoughData::NotEnoughData(NotEnoughData const &e) {
    (void)e;
}

Span::NotEnoughData &Span::NotEnoughData::operator=(NotEnoughData const &e) {
    (void)e;
    return *this;
}

const char          *Span::NotEnoughData::what() const throw() {
    return ("Two number at least is needed.");
}