#ifndef SFML_MATH_ALGEBRA_HPP
#define SFML_MATH_ALGEBRA_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>

namespace sfmath
{
    template<typename L, typename R>
    inline auto dot(const sf::Vector2<L> &lhs, const sf::Vector2<R> &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    template<typename L, typename R>
    inline auto dot(const sf::Vector3<L> &lhs, const sf::Vector3<R> &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template<typename L, typename R>
    inline auto cross(const sf::Vector3<L> &lhs, const sf::Vector3<R> &rhs)
    {
        sf::Vector3<decltype(L() + R())> ret;
        ret.x = lhs.y * rhs.z - lhs.z * rhs.y;
        ret.y = lhs.z * rhs.x - lhs.x * rhs.z;
        ret.x = lhs.x * rhs.y - lhs.y * rhs.x;
        return ret;
    }

    template<typename T>
    inline auto length(const sf::Vector2<T> &v)
    {
        return std::sqrt(length2(v));
    }

    // Length2 return always float,
    // unless for double and long double
    template<typename T>
    inline float length2(const sf::Vector2<T> &v)
    {
        const sf::Vector2f vf(v);
        return dot(vf, vf);
    }

    inline double length2(const sf::Vector2<double> &v)
    {
        return dot(v, v);
    }

    inline long double length2(const sf::Vector2<long double> &v)
    {
        return dot(v, v);
    }

    template<typename T>
    inline auto length(const sf::Vector3<T> &v)
    {
        return std::sqrt(length2(v));
    }

    template<typename T>
    inline float length2(const sf::Vector3<T> &v)
    {
        const sf::Vector3f vf(v);
        return dot(vf, vf);
    }

    inline double length2(const sf::Vector3<double> &v)
    {
        return dot(v, v);
    }

    inline long double length2(const sf::Vector3<long double> &v)
    {
        return dot(v, v);
    }
}

#endif
