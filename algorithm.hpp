#ifndef CLL_ALGORITHM_HPP
#define CLL_ALGORITHM_HPP

#include "types.hpp"

namespace cll
{
	constexpr auto StrLen(char const* str) -> cll::sizet
	{
		cll::sizet len{};
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
	constexpr auto Fill(T* start, cll::sizet count, T const& value) -> void
	{
		Fill(start, start + count, value);
	}	
	template<typename T>
	constexpr auto memcpy(T* src, T* dest, cll::sizet count) -> void
	{
		while(count-- > 0) *dest++ = *src++;
	}

}


#endif //#ifndef CLL_ALGORITHM_HPP
