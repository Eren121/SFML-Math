#ifndef MATH_H
#define MATH_H

#include "Math/Traits.h"
#include <iostream>
#include <cmath>

template
<
    typename T,
    typename = sf::IntrospectionHelper<T>
>
std::ostream& operator <<(std::ostream& lhs, const T& rhs)
{
    bool first = true;

    lhs << "(";

    sf::begin(rhs);

    for(const auto& i : rhs) {

        if(first) {

            first = false;

        } else {

            lhs << ", ";
        }

        lhs << i;
    }

    lhs << ")";

    return lhs;
}

namespace sf
{
    using OutPrecision = float;

    template
    <
        typename Out = OutPrecision,
        typename In,
        typename = IntrospectionHelper<In>
    >
    Out dot(In const& a, In const& b)
    {
        Out ret(0);
        auto it = begin(a);

        for(auto const& i : b) {
            ret += *it * i;
            ++it;
        }

        return ret;
    }

    template
    <
        typename Out = OutPrecision,
        typename In,
        typename = IntrospectionHelper<In>
    >
    Out length2(In const& in)
    {
        return dot(in, in);
    }

    template
    <
        typename Out = OutPrecision,
        typename In,
        typename = IntrospectionHelper<In>
    >
    Out length(In const& in)
    {
        return std::sqrt(length2(in));
    }

    template
    <
        typename Out = OutPrecision,
        typename In,
        typename = IntrospectionHelper<In>
    >
    Out distance(In const& a, In const& b)
    {
        return length(a - b);
    }
}

#endif // MATH_H
