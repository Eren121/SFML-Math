#ifdef SFML_MATH_DISABLE_INCLUDE_PROTECTION

// Component-wise functions

#ifndef SFML_MATH_FUNC
#   error You should define SFML_MATH_FUNC(comp, v1, [v2, [v3]]) before including this file
#endif

#ifndef SFML_MATH_FUNC_NARGS
#   error You should define SFML_MATH_FUNC_NARGS as 1, 2 or 3 before including this file
#endif

#ifndef SFML_MATH_FUNC_NAME
#   error You should define SFML_MATH_FUNC_NAME before including this file
#endif

#define SFML_MATH_CONCAT2(a, b) a##b
#define SFML_MATH_CONCAT(a, b) SFML_MATH_CONCAT2(a, b)
#define SFML_MATH_FUNC_WRAP(...) SFML_MATH_FUNC(__VA_ARGS__)

#if SFML_MATH_FUNC_NARGS == 1
#   define SFML_MATH_DECL_PARAMS(type) type v1
#   define SFML_MATH_PARAMS(comp) v1.comp
#elif SFML_MATH_FUNC_NARGS == 2
#   define SFML_MATH_DECL_PARAMS(type) type v1, type v2
#   define SFML_MATH_PARAMS(comp) v1.comp, v2.comp
#elif SFML_MATH_FUNC_NARGS == 3
#   define SFML_MATH_DECL_PARAMS(type) type v1, type v2, type v3
#   define SFML_MATH_PARAMS(comp) v1.comp, v2.comp, v3.comp
#else
#   error SFML_MATH_FUNC_NARGS is defined but is not equals to 1, 2 or 3.
#endif

template<typename T>
inline sf::Vector2<T> SFML_MATH_FUNC_NAME(SFML_MATH_DECL_PARAMS(const sf::Vector2<T>&))
{
    sf::Vector2<T> ret;
    ret.x = SFML_MATH_FUNC_WRAP(SFML_MATH_PARAMS(x));
    ret.y = SFML_MATH_FUNC_WRAP(SFML_MATH_PARAMS(y));
    return ret;
}

template<typename T>
inline sf::Vector3<T> SFML_MATH_FUNC_NAME(SFML_MATH_DECL_PARAMS(const sf::Vector3<T>&))
{
    sf::Vector2<T> ret;
    ret.x = SFML_MATH_FUNC_WRAP(SFML_MATH_PARAMS(x));
    ret.y = SFML_MATH_FUNC_WRAP(SFML_MATH_PARAMS(y));
    ret.z = SFML_MATH_FUNC_WRAP(SFML_MATH_PARAMS(z));
    return ret;
}

#undef SFML_MATH_FUNC
#undef SFML_MATH_FUNC_NAME
#undef SFML_MATH_FUNC_NARGS
#undef SFML_MATH_FUNC_WRAP

#undef SFML_MATH_CONCAT2
#undef SFML_MATH_CONCAT
#undef SFML_MATH_DECL_PARAMS
#undef SFML_MATH_PARAMS

#endif