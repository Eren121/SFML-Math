#ifndef TRAITS_H
#define TRAITS_H

#include <array>
#include <tuple>

namespace sf
{
    template<typename T>
    struct Comparable
    {
        friend bool
        operator ==(const T& lhs, const T& rhs)
        {
            return lhs.compare(rhs) == 0;
        }

        friend bool
        operator !=(const T& lhs, const T& rhs)
        {
            return !(lhs == rhs);
        }

        friend bool
        operator <(const T& lhs, const T& rhs)
        {
            return lhs.compare(rhs) < 0;
        }

        friend bool
        operator <=(const T& lhs, const T& rhs)
        {
            return lhs.compare(rhs) <= 0;
        }

        friend bool
        operator >(const T& lhs, const T& rhs)
        {
            return lhs.compare(rhs) > 0;
        }

        friend bool
        operator >=(const T& lhs, const T& rhs)
        {
            return lhs.compare(rhs) >= 0;
        }
    };

    template<typename T>
    struct MemberFieldInfo;

    template<typename T, typename V>
    struct MemberFieldInfo<V T::*>
    {
        using type = T;
        using value_type = V;
    };

    template<typename T>
    struct Introspection {};

    template
    <
        typename T,
        typename = decltype(Introspection
        <
            std::remove_cv_t
            <
                std::remove_const_t
                <
                    T
                >
            >
        >
        ::members)
    >
    struct IntrospectionHelper
    {
        using array_type = std::remove_reference_t
        <
            std::remove_cv_t
            <
                decltype(Introspection<std::remove_cv_t<T>>::members())
            >
        >;

        using pointer_type = typename array_type::value_type;

        using value_type = std::conditional_t
        <
            std::is_const_v
            <
                T
            >,

            typename MemberFieldInfo
            <
                pointer_type
            >
            ::value_type const,

            typename MemberFieldInfo
            <
                pointer_type
            >
            ::value_type
        >;

        enum {
            Size = std::tuple_size<array_type>::value
        };

        static inline const array_type& members()
        {
            return Introspection
            <
                std::remove_cv_t
                <
                    T
                >
            >::members();
        }
    };

    template<typename T, typename = IntrospectionHelper<T>>
    class Iterator
        : public Comparable<Iterator<T>>
    {
    private:
        T& container;
        size_t offset;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = typename IntrospectionHelper<T>::value_type;

        using difference_type = size_t;
        using pointer = value_type*;
        using reference = value_type&;

        Iterator(T& container, size_t offset = 0)
            : container(container),
              offset(offset) {}

        Iterator(T& container, nullptr_t)
            : container(container),
              offset(IntrospectionHelper<T>::Size) {}

        value_type& operator*()
        {
            value_type T::* mem = IntrospectionHelper<T>::members()[offset];
            return container.*mem;
        }

        Iterator& operator++()
        {
            ++offset;
            return *this;
        }

        Iterator operator++(int)
        {
            return {container, offset++};
        }

        Iterator& operator--()
        {
            --offset;
            return *this;
        }

        Iterator operator--(int)
        {
            return {container, offset--};
        }

        Iterator& operator+=(difference_type i)
        {
            offset += i;
            return *this;
        }

        Iterator& operator-=(difference_type i)
        {
            offset -= i;
            return *this;
        }

        Iterator operator+(const Iterator& other)
        {
            return {container, offset + other.offset};
        }

        Iterator operator-(const Iterator& other)
        {
            return {container, offset - other.offset};
        }

        difference_type compare(const Iterator& other) const
        {
            return offset - other.offset;
        }
    };

    template<typename T, typename = IntrospectionHelper<T>>
    Iterator<T> begin(T& container)
    {
        return Iterator(container);
    }

    template<typename T, typename = IntrospectionHelper<T>>
    Iterator<T> end(T& container)
    {
        return Iterator(container, nullptr);
    }
}

#include "TraitsImpl.h"

template class sf::Iterator<sf::Vector2f>;
template class sf::Iterator<sf::Vector2i>;
template class sf::Iterator<sf::Vector3f>;
template class sf::Iterator<sf::Vector3i>;
template class sf::Iterator<sf::Color>;

template class sf::Iterator<const sf::Vector2f>;
template class sf::Iterator<const sf::Vector2i>;
template class sf::Iterator<const sf::Vector3f>;
template class sf::Iterator<const sf::Vector3i>;
template class sf::Iterator<const sf::Color>;

#endif // TRAITS_H
