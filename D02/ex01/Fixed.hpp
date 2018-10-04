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