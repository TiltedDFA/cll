#ifndef CLL_ALGORITHM_HPP
#define CLL_ALGORITHM_HPP

#include <iostream>

#include "types.hpp"

namespace cll
{
	template<typename Pred, typename T>
	concept UnaryBoolPredicate =
		requires(Pred p, T t)
		{
			//callable
			{ p(t) };

			//result convertable to bool
			{ p(t) ? 0 : 1 };
		};
	constexpr auto StrLen(char const* str) -> cll::size_t
	{
		cll::size_t len{};
		while(*str++ != '\0')++len;
		return len;
	}
	template<typename T>
	constexpr auto Find(T const* start, T const* const end, T const* const value) -> T const*
	{
		while(start != end)
		{
			if(*start == *value) return start;
			++start;
		}
		return end;
	}
	template<typename T>
	constexpr auto Find(T const* start, T const* const end, T&& value) -> T const*
	{
		while(start != end)
		{
			if(*start == value) return start;
			++start;
		}	
		return end;
	}
	template<typename T>
	constexpr auto Fill(T* start, T const* const end, T const& value) -> void
	{
		while(start != end) *start++ = value;
	}
	template<typename T>
	constexpr auto Fill(T* start, cll::size_t count, T const& value) -> void
	{
		Fill(start, start + count, value);
	}	
	template<typename T>
	constexpr auto memcpy(T* src, T* dest, cll::size_t count) -> void
	{
		while(count-- > 0) *dest++ = *src++;
	}
	template<typename T>
	constexpr auto basicprint(T&& val) -> void
	{
		std::cout << val;
	}
	template<typename... T>
	constexpr auto basicprint(T&&...vals) -> void
	{
		(basicprint(std::forward<T>(vals)), ...);
	}
	template<typename... T>
	constexpr auto basicprintln(T&&...vals) -> void
	{
		basicprint(vals...);
		basicprint('\n');
	}
}


#endif //#ifndef CLL_ALGORITHM_HPP
