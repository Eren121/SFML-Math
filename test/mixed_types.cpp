#include <SFML/System.hpp>
#include <SFML/Math.hpp>
#include <catch2/catch.hpp>

template<typename T>
using vec2 = sf::Vector2<T>;

template<typename T>
using vec3 = sf::Vector3<T>;


TEST_CASE("SFML-Math arithmetic works with vectors of different types")
{
    {
        vec2<int> a{1, 2};
        vec2<long> b{3, 4};
        vec2<long> c = a + b;

        REQUIRE(c.x == 4);
        REQUIRE(c.y == 6);
    }

    {
        vec3<int> a{1, 2, 3};
        vec3<long> b{4, 5, 6};
        vec3<long> c = a - b;

        REQUIRE(c.x == -3);
        REQUIRE(c.y == -3);
        REQUIRE(c.z == -3);
    }

    {
        vec2<float> a{1, 2};
        vec2<int> b{3, 4};
        vec2<float> c = a / b;

        REQUIRE(c.x == Approx(1.0f / 3.0f));
        REQUIRE(c.y == Approx(1.0f / 2.0f));
    }

    {
        vec2<short> a{10, 20};
        vec2<int> b{5, 10};
        vec2<int> c = a * b;

        REQUIRE(c.x == 50);
        REQUIRE(c.y == 200);
    }
}