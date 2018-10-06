#include "main.hpp"

Screen::Screen(int height, int width): height(height), width(width) {
    WINDOW *w = initscr();

    this->setWindow(w);
}

Screen::~Screen(void) {}

Screen::Screen(Screen const &ref) {}

int            Screen::getHeight(void) const {
    return this->height;
}

int            Screen::getWidth(void) const {
    return this->width;
}

WINDOW            *Screen::getWindow(void) const {
    return this->window;
}

void           Screen::setHeight(int height) {
    this->height = height;
}

void           Screen::setWidth(int width) {
    this->width = width;
}

void           Screen::setWindow(WINDOW *w) {
    this->window = w;
    std::cout << w << std::endl; 
}