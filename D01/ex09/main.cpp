#include "Logger.hpp"



int main (void) {

    Logger l("text.txt");

    l.log("file", "file test");
    l.log("console", "console test");
    return 0;
} 