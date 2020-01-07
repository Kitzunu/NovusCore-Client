#pragma once
#include <type_safe/strong_typedef.hpp>
#include <limits>

template <class StrongTypedef>
struct ShaderComparison
{
    friend bool operator==(StrongTypedef& lhs, const StrongTypedef& rhs)
    {
        using type = type_safe::underlying_type<StrongTypedef>;
        return static_cast<type&>(lhs) == static_cast<const type&>(rhs);
    }

    friend bool operator==(const StrongTypedef& lhs, const StrongTypedef& rhs)
    {
        using type = type_safe::underlying_type<StrongTypedef>;
        return static_cast<type&>(lhs) == static_cast<const type&>(rhs);
    }

    friend bool operator!=(StrongTypedef& lhs, const StrongTypedef& rhs)
    {
        using type = type_safe::underlying_type<StrongTypedef>;
        return static_cast<type&>(lhs) != static_cast<const type&>(rhs);
    }

    friend bool operator!=(const StrongTypedef& lhs, const StrongTypedef& rhs)
    {
        using type = type_safe::underlying_type<StrongTypedef>;
        return static_cast<type&>(lhs) != static_cast<const type&>(rhs);
    }
};

// If you want to change the underlying integer type used for these handles, change the type under "HERE"
//                                                                HERE
struct __ShaderHandle : type_safe::strong_typedef<__ShaderHandle, u16>, ShaderComparison<__ShaderHandle>
{
    using strong_typedef::strong_typedef;
    using type = type_safe::underlying_type<__ShaderHandle>;

    static size_t MaxValue()
    {
        return std::numeric_limits<type>::max();
    }

    static type MaxValueTyped()
    {
        return (type)std::numeric_limits<type>::max();
    }
};

struct ShaderHandleVert :type_safe::strong_typedef<ShaderHandleVert, __ShaderHandle>, ShaderComparison<ShaderHandleVert>
{
    using strong_typedef::strong_typedef;

    static ShaderHandleVert Invalid()
    {
        return ShaderHandleVert(static_cast<ShaderHandleVert>(__ShaderHandle(__ShaderHandle::MaxValueTyped())));
    }
};

struct ShaderHandleFrag :type_safe::strong_typedef<ShaderHandleFrag, __ShaderHandle>, ShaderComparison<ShaderHandleFrag>
{
    using strong_typedef::strong_typedef;

    static ShaderHandleFrag Invalid()
    {
        return ShaderHandleFrag(static_cast<ShaderHandleFrag>(__ShaderHandle(__ShaderHandle::MaxValueTyped())));
    }
};

struct ShaderHandleComp :type_safe::strong_typedef<ShaderHandleComp, __ShaderHandle>, ShaderComparison<ShaderHandleComp>
{
    using strong_typedef::strong_typedef;

    static ShaderHandleComp Invalid()
    {
        return ShaderHandleComp(static_cast<ShaderHandleComp>(__ShaderHandle(__ShaderHandle::MaxValueTyped())));
    }
};