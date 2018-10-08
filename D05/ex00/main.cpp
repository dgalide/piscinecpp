#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("b1");
    Bureaucrat b2("b2");

    try {
        b1.increment();
        std::cout << b1;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}