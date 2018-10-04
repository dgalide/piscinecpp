#ifndef FIXED_HPP
 #define FIXED_HPP

 #include <iostream>
 #include <cmath>

class Fixed {
    public:

        Fixed(void);
        Fixed(int value);
        Fixed(float value);
        Fixed(Fixed const &ref);

        Fixed &operator=(const Fixed &ref);
        Fixed operator+(const Fixed &ref);
        Fixed operator-(const Fixed &ref);
        Fixed operator*(const Fixed &ref);
        Fixed operator/(const Fixed &ref);

        bool operator<(Fixed const &ref) const;
        bool operator>(Fixed const &ref) const;
        bool operator>=(Fixed const &ref) const;
        bool operator<=(Fixed const &ref) const;
        bool operator==(Fixed const &ref) const;
        bool operator!=(Fixed const &ref) const;

        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

        static const Fixed &min(Fixed const &r1, Fixed const &r2);
        static const Fixed &max(Fixed const &r1, Fixed const &r2);

        ~Fixed(void);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;

    private:

        int                 value;
        static const int    nbFractional;
};

std::ostream    &operator<<(std::ostream &out, Fixed const &val);

#endif