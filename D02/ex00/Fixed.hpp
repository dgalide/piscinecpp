#ifndef FIXED_HPP
 #define FIXED_HPP

 #include <iostream>

class Fixed {
    public:

        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const &ref);
        Fixed &operator=(const Fixed &ref);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:

        int                 value;
        static const int    nbFractional;
};

#endif