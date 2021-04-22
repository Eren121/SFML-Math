#ifndef SFML_MATH_HPP
#define SFML_MATH_HPP

#include "Math/Arithmetic.hpp"
#include "Math/ToString.hpp"
#include "Math/StreamOutput.hpp"
#include "Math/Algebra.hpp"

#ifndef SFML_MATH_DISABLE_ALL
    namespace sf
    {
#       ifndef SFML_MATH_DISABLE_ARITHMETIC
            using sfmath::operator+;
            using sfmath::operator-;
            using sfmath::operator*;
            using sfmath::operator/;
            using sfmath::operator+=;
            using sfmath::operator-=;
            using sfmath::operator*=;
            using sfmath::operator/=;
#       endif

#       ifndef SFML_MATH_DISABLE_STRING_CONVERSION
            using sfmath::to_string;
#       endif

#       ifndef SFML_MATH_DISABLE_STREAM_OUTPUT
            using sfmath::operator<<;
#       endif

#       ifndef SFML_MATH_DISABLE_ALGEBRA
            using sfmath::length2;
            using sfmath::length;
            using sfmath::dot;
            using sfmath::cross;
#       endif
    }
#endif

#endif