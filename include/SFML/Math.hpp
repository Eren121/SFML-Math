#ifndef SFML_MATH_HPP
#define SFML_MATH_HPP

#include "Math/Arithmetic.hpp"
#include "Math/ToString.hpp"
#include "Math/StreamOutput.hpp"
#include "Math/Algebra.hpp"
#include "Math/Utility.hpp"
#include <SFML/Graphics/Rect.hpp>

#ifndef SFML_MATH_DISABLE_ALL
namespace sf
{
#ifndef SFML_MATH_DISABLE_ARITHMETIC
    using sfmath::operator+;
    using sfmath::operator-;
    using sfmath::operator*;
    using sfmath::operator/;
    using sfmath::operator+=;
    using sfmath::operator-=;
    using sfmath::operator*=;
    using sfmath::operator/=;
#endif

#ifndef SFML_MATH_DISABLE_STRING_CONVERSION
    using sfmath::to_string;
#endif

#ifndef SFML_MATH_DISABLE_STREAM_OUTPUT
    using sfmath::operator<<;
#endif

#ifndef SFML_MATH_DISABLE_ALGEBRA
    using sfmath::length2;
    using sfmath::length;
    using sfmath::dot;
    using sfmath::cross;
#endif

#ifndef SFML_MATH_DISABLE_UTILITY
    using sfmath::max;
    using sfmath::min;
    using sfmath::ceil;
    using sfmath::floor;
    using sfmath::clamp;

    template<typename T>
    sf::Vector2<T> size(const sf::Rect<T> &rect)
    {
        return {rect.width, rect.height};
    }

    template<typename T>
    sf::Vector2<T> position(const sf::Rect<T> &rect)
    {
        return {rect.left, rect.top};
    }
#endif

}
#endif

#endif