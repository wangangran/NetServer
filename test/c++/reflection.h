//
// Created by Administrator on 2023/8/9.
//

#ifndef SUNWAR_REFLECTION_H
#define SUNWAR_REFLECTION_H

#include <variant>

template<typename T>
constexpr std::size_t MembersCount = 0;

struct universalType {
    template<typename T>
    operator T();
};

template<typename T, typename... Args>
consteval std::size_t MemberCountImpl() {
    if constexpr (requires {
        T{
                {Args{}}...,
                { universalType{}}
        };
    }) {
        return MemberCountImpl<T, Args..., universalType>();
    } else {
        return sizeof...(Args);
    }
}

template<typename T>
consteval std::size_t MemberCount() {
    // 说明用户已经特化该类的成员数量，直接返回
    if constexpr (MembersCount<T> > 0) {
        return MembersCount<T>;
    } else {
        return MemberCountImpl<T>();
    }
}

constexpr decltype(auto) VisitMembers(auto &&object) {
    using type = std::remove_cvref_t<decltype(object)>;
    constexpr auto Count = MemberCount<type>();
    return Count;
}

#endif //SUNWAR_REFLECTION_H
