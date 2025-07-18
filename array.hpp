#ifndef CLL_ARRAY_HPP
#define CLL_ARRAY_HPP

#include <utility>

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
		constexpr auto Size() const noexcept -> cll::sizet {return SIZE;}

		// constexpr auto cbegin() const noexcept -> T const* {return data_;}
		constexpr auto begin() noexcept -> T* {return data_;}
		//for some reason when trying to use this array as a const in a for each
		//loop, it doesn't look for cbegin but rather fails as it wants a begin marked as const.
		constexpr auto begin() const noexcept -> T const* {return data_;}

		// constexpr auto cend() const noexcept -> T const* {return data_ + SIZE;}
		constexpr auto end() noexcept -> T* {return data_ + SIZE;}
		constexpr auto end() const noexcept -> T const* {return data_ + SIZE;}

		constexpr auto operator[](cll::sizet idx) noexcept -> T& {return data_[idx];}
		constexpr auto operator[](cll::sizet idx) const noexcept -> T const& {return data_[idx];}
	private:
		template<typename Arg, typename... Args>
		constexpr auto InitFromList(cll::sizet idx, Arg&& arg, Args&&... args) -> void
		{
			data_[idx] = std::forward<Arg>(arg);
			InitFromList(idx + 1, std::forward<Args>(args)...);
		}
		//base case
		template<typename Arg>
		constexpr auto InitFromList(cll::sizet idx, Arg&& arg) -> void {data_[idx] = std::forward<Arg>(arg);}
	private:
		T data_[SIZE];
	};
}
#endif //#ifndef CLL_ARRAY_HPP