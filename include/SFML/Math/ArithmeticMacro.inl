#ifdef SFML_MATH_DISABLE_INCLUDE_PROTECTION

#include <SFML/System/Vector2.hpp> // For syntax higlighting in IDEs
#include <SFML/System/Vector3.hpp> // Same

#ifndef SFML_MATH_OPERATOR
#   error You should define SFML_MATH_OPERATOR before including this file
#endif

#define SFML_MATH_CONCAT2(a, b) a##b
#define SFML_MATH_CONCAT(a, b) SFML_MATH_CONCAT2(a, b)
#define SFML_MATH_ASSIGN_OPERATOR SFML_MATH_CONCAT(SFML_MATH_OPERATOR, =)

////////////////////////////////////////////////////////////
// When both arguments are vectors
////////////////////////////////////////////////////////////

template<typename L, typename R>
inline auto
operator SFML_MATH_OPERATOR(const sf::Vector2<L> &lhs, const sf::Vector2<R> &rhs)
{
    sf::Vector2<decltype(L() SFML_MATH_OPERATOR R())> ret;
    ret.x = lhs.x SFML_MATH_OPERATOR rhs.x;
    ret.y = lhs.y SFML_MATH_OPERATOR rhs.y;
    return ret;
}

template<typename L, typename R>
inline auto &
operator SFML_MATH_ASSIGN_OPERATOR(sf::Vector2<L> &lhs, const sf::Vector2<R> &rhs)
{
    lhs.x SFML_MATH_ASSIGN_OPERATOR rhs.x;
    lhs.y SFML_MATH_ASSIGN_OPERATOR rhs.y;
    return lhs;
}

template<typename L, typename R>
inline auto
operator SFML_MATH_OPERATOR(const sf::Vector3<L> &lhs, const sf::Vector3<R> &rhs)
{
    sf::Vector3<decltype(L() SFML_MATH_OPERATOR R())> ret;
    ret.x = lhs.x SFML_MATH_OPERATOR rhs.x;
    ret.y = lhs.y SFML_MATH_OPERATOR rhs.y;
    ret.z = lhs.z SFML_MATH_OPERATOR rhs.z;
    return ret;
}

template<typename L, typename R>
inline auto &
operator SFML_MATH_ASSIGN_OPERATOR(sf::Vector3<L> &lhs, const sf::Vector3<R> &rhs)
{
    lhs.x SFML_MATH_ASSIGN_OPERATOR rhs.x;
    lhs.y SFML_MATH_ASSIGN_OPERATOR rhs.y;
    lhs.z SFML_MATH_ASSIGN_OPERATOR rhs.z;
    return lhs;
}

////////////////////////////////////////////////////////////
// When the left argument is a vector, and the right argument is a scalar
////////////////////////////////////////////////////////////

template<typename L, typename R>
inline auto
operator SFML_MATH_OPERATOR(const sf::Vector2<L> &lhs, const R &rhs)
{
    sf::Vector2<decltype(L() SFML_MATH_OPERATOR R())> ret;
    ret.x = lhs.x SFML_MATH_OPERATOR rhs;
    ret.y = lhs.y SFML_MATH_OPERATOR rhs;
    return ret;
}

template<typename L, typename R>
inline auto &
operator SFML_MATH_ASSIGN_OPERATOR(sf::Vector2<L> &lhs, const R &rhs)
{
    lhs.x SFML_MATH_ASSIGN_OPERATOR rhs;
    lhs.y SFML_MATH_ASSIGN_OPERATOR rhs;
    return lhs;
}

template<typename L, typename R>
inline auto
operator SFML_MATH_OPERATOR(const sf::Vector3<L> &lhs, const R &rhs)
{
    sf::Vector3<decltype(L() SFML_MATH_OPERATOR R())> ret;
    ret.x = lhs.x SFML_MATH_OPERATOR rhs;
    ret.y = lhs.y SFML_MATH_OPERATOR rhs;
    ret.z = lhs.z SFML_MATH_OPERATOR rhs;
    return ret;
}

template<typename L, typename R>
inline auto &
operator SFML_MATH_ASSIGN_OPERATOR(sf::Vector3<L> &lhs, const R &rhs)
{
    lhs.x SFML_MATH_ASSIGN_OPERATOR rhs.x;
    lhs.y SFML_MATH_ASSIGN_OPERATOR rhs.y;
    lhs.z SFML_MATH_ASSIGN_OPERATOR rhs.z;
    return lhs;
}

////////////////////////////////////////////////////////////
// When the left argument is a scalar, and the right argument is a vector
// In this case, no assignment operator is defined.
////////////////////////////////////////////////////////////

template<typename L, typename R>
inline auto
operator SFML_MATH_OPERATOR(const L &lhs, const sf::Vector2<R> &rhs)
{
    sf::Vector2<decltype(L() SFML_MATH_OPERATOR R())> ret;
    ret.x = lhs SFML_MATH_OPERATOR rhs.x;
    ret.y = lhs SFML_MATH_OPERATOR rhs.y;
    return ret;
}

template<typename L, typename R>
inline auto
operator SFML_MATH_OPERATOR(const L &lhs, const sf::Vector3<R> &rhs)
{
    sf::Vector3<decltype(L() SFML_MATH_OPERATOR R())> ret;
    ret.x = lhs SFML_MATH_OPERATOR rhs.x;
    ret.y = lhs SFML_MATH_OPERATOR rhs.y;
    ret.z = lhs SFML_MATH_OPERATOR rhs.z;
    return ret;
}

#undef SFML_MATH_OPERATOR
#undef SFML_MATH_ASSIGN_OPERATOR

#endif
