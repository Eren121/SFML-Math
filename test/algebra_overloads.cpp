#include <SFML/System.hpp>
#include <SFML/Math.hpp>
#include <catch2/catch.hpp>
#include <iostream>

template<typename T>
using vec2 = sf::Vector2<T>;

template<typename T>
using vec3 = sf::Vector3<T>;


TEST_CASE("SFML-Math can compute common algebra functions with float by default or higher precision", "[compile-time]")
{
    vec3<float> i;

    {
        vec2<int> v;
        auto x = length(v);
        auto y = length2(v);

        static_assert(std::is_same_v<decltype(x), float>);
        static_assert(std::is_same_v<decltype(y), float>);
    }
    {
        vec2<float> v;
        auto x = length(v);
        auto y = length2(v);

        static_assert(std::is_same_v<decltype(x), float>);
        static_assert(std::is_same_v<decltype(y), float>);
    }
    {
        vec2<short> v;
        auto x = length(v);
        auto y = length2(v);

        static_assert(std::is_same_v<decltype(x), float>);
        static_assert(std::is_same_v<decltype(y), float>);
    }
    {
        vec2<unsigned char> v;
        auto x = length(v);
        auto y = length2(v);

        static_assert(std::is_same_v<decltype(x), float>);
        static_assert(std::is_same_v<decltype(y), float>);
    }
    {
        vec2<double> v;
        auto x = length(v);
        auto y = length2(v);

        static_assert(std::is_same_v<decltype(x), double>);
        static_assert(std::is_same_v<decltype(y), double>);
    }
    {
        vec2<long double> v;
        auto x = length(v);
        auto y = length2(v);

        static_assert(std::is_same_v<decltype(x), long double>);
        static_assert(std::is_same_v<decltype(y), long double>);
    }
    {
        vec3<long double> a;
        vec3<double> b;
        vec3<long double> x = cross(a, b);
    }
    {
        vec3<int> a;
        vec3<double> b;
        vec3<double> x = cross(a, b);
    }
    {
        vec3<int> a;
        vec3<float> b;
        vec3<float> x = cross(a, b);
    }
    {
        vec3<int> a;
        vec3<int> b;
        vec3<int> x = cross(a, b);
    }
    {
        vec3<short> a;
        vec3<short> b;
        vec3<int> x = cross(a, b);
    }
}

