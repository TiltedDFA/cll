#ifndef CLL_ALGORITHM_HPP
#define CLL_ALGORITHM_HPP

#include "types.hpp"

namespace cll
{
	constexpr cll::sizet StrLen(char const* str)
	{
		cll::sizet len{};
		while(*str++ != '\0')++len;
		return len;
	}
	template<typename T>
	constexpr T const* Find(T const* start, T const* const end, T const* const value)
	{
		while(start != end)
		{
			if(*start == *value) return start;
			++start;
		}
		return end;
	}
	template<typename T>
	constexpr T const* Find(T const* start, T const* const end, T&& value)
	{
		while(start != end)
		{
			if(*start == value) return start;
			++start;
		}	
		return end;
	}
	template<typename T>
	constexpr void Fill(T* start, T const* const end, T const& value)
	{
		while(start != end) *start++ = value;
	}
	template<typename T>
	constexpr void Fill(T* start, cll::sizet count, T const& value)
	{
		Fill(start, start + count, value);
	}	
	template<typename T>
	constexpr void memcpy(T* src, T* dest, cll::sizet count)
	{
		while(count-- > 0) *dest++ = *src++;
	}

}


#endif //#ifndef CLL_ALGORITHM_HPP
