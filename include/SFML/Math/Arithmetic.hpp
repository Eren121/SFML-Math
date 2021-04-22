#ifndef SFML_MATH_ARITHMETIC_HPP
#define SFML_MATH_ARITHMETIC_HPP

////////////////////////////////////////////////////////////
/// \file
/// \brief Define the arithmetic operators for vectors.
///
/// Define the arithmetic operations (addition, division, multiplication, subtraction),
/// and there assignement version (Example: \code += \endcode for addition).
/// For each of those operations, define 3 different overload:
///  - Both operands are vectors. Example: vector + vector
///  - Left operand is vector, right operand is scalar. Example: vector + 1
///  - Left operand is scalar, right operand is vector. Example: 1 + vector
/// For operations when a scalar appears, the scalar don't have to be the same type as the vector.
/// If the types are different, then the type of the vector returned is what type would be returned if both
/// operands were scalars.
/// SFML already defines some of these operations, so those are disabled in this file to not conflict with SFML.
///
////////////////////////////////////////////////////////////

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

#define SFML_MATH_DISABLE_INCLUDE_PROTECTION

namespace sfmath
{
#   define SFML_MATH_OPERATOR +
#   include "ArithmeticMacro.inl"

#   define SFML_MATH_OPERATOR -
#   include "ArithmeticMacro.inl"

#   define SFML_MATH_OPERATOR *
#   include "ArithmeticMacro.inl"

#   define SFML_MATH_OPERATOR /
#   include "ArithmeticMacro.inl"
}

#undef SFML_MATH_DISABLE_INCLUDE_PROTECTION

#endif
