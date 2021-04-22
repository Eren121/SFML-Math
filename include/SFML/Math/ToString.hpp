#ifndef SFML_MATH_TOSTRING_HPP
#define SFML_MATH_TOSTRING_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>
#include <ostream>
#include <sstream>

namespace sfmath
{
    template<typename T>
    inline std::string to_string(const sf::Vector2<T> &v)
    {
        std::ostringstream ss;
        ss << "vec2(" << v.x << ", " << v.y << ")";

        return ss.str();
    }

    template<typename T>
    inline std::string to_string(const sf::Vector3<T> &v)
    {
        std::ostringstream ss;
        ss << "vec3(" << v.x << ", " << v.y << ", " << v.z << ")";

        return ss.str();
    }

    inline std::string to_string(const sf::Color &c)
    {
        std::ostringstream ss;
        ss << "color(" << static_cast<int>(c.r);
        ss << ", " << static_cast<int>(c.g);
        ss << ", " << static_cast<int>(c.b);
        ss << ", " << static_cast<int>(c.a) << ")";

        return ss.str();
    }
}

#endif
