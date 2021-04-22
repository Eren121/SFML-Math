#include <SFML/System.hpp>
#include <SFML/Math.hpp>
#include <catch2/catch.hpp>
#include <iostream>

template<typename T>
using vec2 = sf::Vector2<T>;

template<typename T>
using vec3 = sf::Vector3<T>;


TEST_CASE("SFML-Math can convert objects to string")
{
    vec2<int> a{1, 2};
    vec3<float> b{1, 2, 3.5f};
    sf::Color c{10, 50, 100, 200};

    std::string str = to_string(a);

    std::cerr << str << std::endl;
    std::cerr << a << std::endl;
    std::cerr << b << std::endl;
    std::cerr << c << std::endl;
}

