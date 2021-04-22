#ifndef SFML_MATH_HPP
#define SFML_MATH_HPP

#include "Math/VectorArithmetic.hpp"
#include "Math/ToString.hpp"
#include "Math/StreamOutput.hpp"

#ifndef SFML_MATH_DISABLE_INTEGRATION
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
    }
#endif

#endif