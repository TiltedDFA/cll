#ifndef CLL_ARRAY_HPP
#define CLL_ARRAY_HPP

#include "algorithm.hpp"

namespace cll
{
	template<typename T, cll::sizet SIZE>
	class Array
	{
	public:
		constexpr Array():
			data_()
		{}

		constexpr Array(T const& value):
			data_()
		{
			cll::Fill(data_, data_ + SIZE, value);
		}
		
		constexpr cll::sizet Size() const noexcept {return SIZE;}

		constexpr T const* cbegin() const noexcept {return data_;}
		constexpr T* begin() noexcept {return data_;}

		constexpr T const* cend() const noexcept {return data_ + SIZE;}
		constexpr T* end() noexcept {return data_ + SIZE;}

		constexpr T& operator[](cll::sizet idx) noexcept {return data_[idx];}
		constexpr T const& operator[](cll::sizet idx) const noexcept {return data_[idx];}
		
	private:
		T data_[SIZE];
	};
}
#endif //#ifndef CLL_ARRAY_HPP
