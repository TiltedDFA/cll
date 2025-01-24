#include "algorithm.hpp"
#include "array.hpp"
#include <iostream>


template<typename T>
void prnt(T const& val)
{
	for(auto&& e : val)
	{
		std::cout << e << '\t';
	}
	std::cout << '\n';
}


int main(void)
{
	char const* message = "Hello world!\n";
	cll::Array<int, 5> myarr;
	myarr[2] = 1243;
	prnt(myarr);
	cll::Array<float, 20> fmyarr{7.9f};
	prnt(fmyarr);	
	cll::Array<float, 20> cpy1 = fmyarr;
	prnt(cpy1);
	cll::Array<float, 20> cpy2;
	cll::memcpy(fmyarr.begin(), cpy2.begin(), 20);
	prnt(cpy2);

	std::cout << message << cll::Find(message, message + cll::StrLen(message), 'q') << '\n' << cll::StrLen(message) << (myarr.end()) << std::endl;
	return 0;
}




