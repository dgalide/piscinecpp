#include "Fixed.hpp"

int main(void) {

Fixed a;
Fixed const b( Fixed( 10) * Fixed( 2 ) );
Fixed aa(7.5f);
Fixed bb(10);

std::cout << aa + bb << std::endl;
std::cout << aa * bb << std::endl;
std::cout << aa / bb << std::endl;
std::cout << (aa < bb) << std::endl;
aa = aa + bb;
std::cout << aa << std::endl;

std::cout << (aa == Fixed(17.5f)) << std::endl;
std::cout << (aa != Fixed(17.5f)) << std::endl;
std::cout << (aa >= Fixed(17.5f)) << std::endl;
std::cout << (aa <= Fixed(17.5f)) << std::endl;
std::cout << (aa <= Fixed(17.4f)) << std::endl;
std::cout << (aa <= Fixed(17.6f)) << std::endl;
aa++;

// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}