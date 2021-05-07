#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>

#define SFML_MATH_DISABLE_INCLUDE_PROTECTION

namespace sfmath
{
#   define SFML_MATH_FUNC_NAME floor
#   define SFML_MATH_FUNC_NARGS 1
#   define SFML_MATH_FUNC(c1) std::floor(c1)
#   include "UtilityMacro.inl"

#   define SFML_MATH_FUNC_NAME ceil
#   define SFML_MATH_FUNC_NARGS 1
#   define SFML_MATH_FUNC(c1) std::ceil(c1)
#   include "UtilityMacro.inl"

#   define SFML_MATH_FUNC_NAME min
#   define SFML_MATH_FUNC_NARGS 2
#   define SFML_MATH_FUNC(c1, c2) std::min(c1, c2)
#   include "UtilityMacro.inl"

#   define SFML_MATH_FUNC_NAME max
#   define SFML_MATH_FUNC_NARGS 2
#   define SFML_MATH_FUNC(c1, c2) std::max(c1, c2)
#   include "UtilityMacro.inl"

#   define SFML_MATH_FUNC_NAME clamp
#   define SFML_MATH_FUNC_NARGS 3
#   define SFML_MATH_FUNC(x, low, high) std::clamp(x, low, high)
#   include "UtilityMacro.inl"

}

#undef SFML_MATH_DISABLE_INCLUDE_PROTECTION