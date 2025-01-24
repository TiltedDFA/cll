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
			Vector()
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
		Vector<T>& operator=(Vector<T>&& other)
		{
			delete[] data_;
			data_ = other.data_;
			other.data_ = nullptr;
			size_ = other.size_;
			capacity_ = other.capacity_;
		}
		T& operator[](cll::sizet index)
		{
			return data_[index];
		}
		cll::sizet Size() const {return size_;}
		void push_back(T const& val)
		{
			if(!can_handle_more()) resize();
			data_[size_++] = val;
		}
		T* begin() {return data_;}
		T* end() {return data_ + size_;}
		T const* cbegin() const {return data_;}
		T const* cend() const {return data_ + size_;}




	private:
		bool can_handle_more(cll::sizet count_to_add = 1)
		{
			return size_ + count_to_add <= capacity_;
		}
		void resize()
		{
			T* tmp = new T[capacity_ *= 2]{};
			cll::memcpy(data_, tmp, size_);
			delete[] data_;
			data = tmp;	
		}
	private:
		T* data_;
		cll::sizet size_;
		cll::sizet capacity_;
	};





}


#endif // CLL_VECTOR_HPP
