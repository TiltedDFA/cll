#ifndef CLL_VECTOR_HPP
#define CLL_VECTOR_HPP

#include "algorithm.hpp"
namespace cll
{

	template<typename T>
	class Vector
	{
	public:
		constexpr Vector():
			data_(nullptr),
			size_(0),
			capacity_(0)
		{}
		Vector(cll::sizet size):
			data_(nullptr),
			size_(size),
			capacity_(size)
		{
			data_ = new T[size]{};
		}
		~Vector()
		{
			delete[] data_;
		}
		Vector(Vector<T> const& other)
		{
			delete[] data_;
			data_ = new T[other.size_];
			cll::memcpy(other.data_, data_, other.size_);
			size_ = other.size_;
			capacity_ = other.capacity_;
		}
		Vector<T>& operator=(Vector<T> const& other)
		{
			delete[] data_;
			data_ = new T[other.size_];
			cll::memcpy(other.data_, data_, other.size_);
			size_ = other.size_;
			capacity_ = other.capacity_;
		}
		Vector(Vector<T>&& other)
		{
			delete[] data_;
			data_ = other.data_;
			other.data_ = nullptr;
			size_ = other.size_;
			capacity_ = other.capacity_;
		}
		auto operator=(Vector<T>&& other) -> Vector<T>&
		{
			delete[] data_;
			data_ = other.data_;
			other.data_ = nullptr;
			size_ = other.size_;
			capacity_ = other.capacity_;
		}
		auto operator[](cll::sizet index) -> T&
		{
			return data_[index];
		}
		[[nodiscard]] auto Size() const -> cll::sizet {return size_;}
		auto push_back(T const& val) -> void
		{
			if(!can_handle_more()) resize();
			data_[size_++] = val;
		}
		auto begin() -> T* {return data_;}
		auto end() -> T* {return data_ + size_;}
		auto cbegin() const -> T const*  {return data_;}
		auto cend() const -> T const*  {return data_ + size_;}

		auto clear() -> void
		{
			size_ = 0;
		}
	private:
		auto can_handle_more(cll::sizet count_to_add = 1) -> bool
		{
			return size_ + count_to_add <= capacity_;
		}
		auto resize() -> void
		{
			T* tmp = new T[capacity_ *= 2]{};
			cll::memcpy(data_, tmp, size_);
			delete[] data_;
			data_ = tmp;
		}
	private:
		T* data_;
		cll::sizet size_;
		cll::sizet capacity_;
	};





}


#endif // CLL_VECTOR_HPP
