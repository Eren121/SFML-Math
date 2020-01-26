#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Traits.h"

namespace sf
{
    template<typename Type, typename Field, size_t Count>
    using __Array = std::array<Field Type::*, Count>;

    template<typename T>
    struct Introspection<Vector2<T>>
    {
        using Vec = Vector2<T>;
        enum { Size = 2 };

        static const __Array<Vec, T, Size>& members()
        {
            static const __Array<Vec, T, Size> mems = {
                &Vec::x, &Vec::y
            };
            return mems;
        }
    };

    template<typename T>
    struct Introspection<Vector3<T>>
    {
        using Vec = Vector3<T>;
        enum { Size = 3 };

        static const __Array<Vec, T, Size>& members()
        {
            static const __Array<Vec, T, Size> mems = {
                &Vec::x, &Vec::y, &Vec::z
            };
            return mems;
        }
    };

    template<>
    struct Introspection<Color>
    {
        using T = decltype(Color::r);
        enum { Size  = 4 };

        static const __Array<Color, T, Size>& members()
        {
            static const __Array<Color, T, Size> mems = {
                &Color::r, &Color::g, &Color::b, &Color::a
            };
            return mems;
        }
    };
}
