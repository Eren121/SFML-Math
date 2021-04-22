#include <SFML/System.hpp>
#include <SFML/Math.hpp>
#include <catch2/catch.hpp>

template<typename T>
using vec2 = sf::Vector2<T>;

template<typename T>
using vec3 = sf::Vector3<T>;


TEST_CASE("SFML-Math arithmetic do not conflict with SFML operators", "[compile-time]")
{
    {
        vec2<int> a{}, b{}, c{};
        c = a + b;
    }
    {
        vec3<int> a{}, b{}, c{};
        c = a + b;
    }

    {
        vec2<float> a{}, b{}, c{};
        c = a / b;
    }
    {
        vec2<int> a{}, b{};
        b = a * 3;
    }
    {
        vec3<float> a{}, b{};
        b = a / 3.0f;
    }
}