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

		constexpr explicit Array(T&& value):
			data_()
		{
			cll::Fill(data_, data_ + SIZE, value);
		}
		template<typename... Args>
		constexpr explicit Array(Args&&... args)
		{
			InitFromList(0, std::forward<Args>(args)...);
		}
		
		[[nodiscard]]
		constexpr cll::sizet Size() const noexcept {return SIZE;}

		// constexpr T const* cbegin() const noexcept {return data_;}
		constexpr T* begin() noexcept {return data_;}
		//for some reason when trying to use this array as a const in a for each
		//loop, it doesn't look for cbegin but rather fails as it wants a begin marked as const.
		constexpr T const* begin() const noexcept {return data_;}

		// constexpr T const* cend() const noexcept {return data_ + SIZE;}
		constexpr T* end() noexcept {return data_ + SIZE;}
		constexpr T const* end() const noexcept {return data_ + SIZE;}

		constexpr T& operator[](cll::sizet idx) noexcept {return data_[idx];}
		constexpr T const& operator[](cll::sizet idx) const noexcept {return data_[idx];}
	private:
		template<typename Arg, typename... Args>
		constexpr void InitFromList(cll::sizet idx, Arg&& arg, Args&&... args)
		{
			data_[idx] = std::forward<Arg>(arg);
			InitFromList(idx + 1, std::forward<Args>(args)...);
		}
		//base case
		template<typename Arg>
		constexpr void InitFromList(cll::sizet idx, Arg&& arg){data_[idx] = std::forward<Arg>(arg);}
	private:
		T data_[SIZE];
	};
}
#endif //#ifndef CLL_ARRAY_HPP
