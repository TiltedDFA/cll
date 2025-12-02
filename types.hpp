#ifndef CLL_TYPES_HPP
#define CLL_TYPES_HPP

namespace cll
{

	using i8 = char;
	using i16 = short;
	using i32 = int;
	using i64 = long long;
	using u8 = unsigned char;
	using u16 = unsigned short;
	using u32 = unsigned int;
	using u64 = unsigned long long;
	using size_t = u64;

	static_assert(sizeof(u32) == 4, "u32 is not 4 bytes");
	static_assert(sizeof(u64) == 8, "u64 is not 8 bytes");
}



#endif //#ifndef CLL_TYPES_HPP
