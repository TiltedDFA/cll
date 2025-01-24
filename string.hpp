#ifndef CLL_STRING_HPP
#define CLL_STRING_HPP

#include "algorithm.hpp"
#include "array.hpp"

namespace cll
{
	class String
	{
	public:
		


	
	private:
		char* data_start_;
		// imagined to be like a writer head
		// points to next free char
		char* data_head_;
	};
}




#endif //#ifndef CLL_STRING_HPP
