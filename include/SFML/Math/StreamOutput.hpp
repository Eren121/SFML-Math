#ifndef SFML_MATH_STREAMOUTPUT_HPP
#define SFML_MATH_STREAMOUTPUT_HPP

#include "ToString.hpp"

namespace sfmath
{
    template<typename T>
    inline std::ostream &operator<<(std::ostream &lhs, const sf::Vector2<T> &rhs)
    {
        lhs << to_string(rhs);
        return lhs;
    }

    template<typename T>
    inline std::ostream &operator<<(std::ostream &lhs, const sf::Vector3<T> &rhs)
    {
        lhs << to_string(rhs);
        return lhs;
    }

    inline std::ostream &operator<<(std::ostream &lhs, const sf::Color &rhs)
    {
        lhs << to_string(rhs);
        return lhs;
    }
}

#endif
