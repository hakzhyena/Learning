#include "Conversion.h"

void Conversion::writeDecimalToCout()
{

}
template <typename T>
constexpr std::size_t bitSize() noexcept
{
	return sizeof(T) * CHAR_BIT;
}

void Conversion::writeBinaryToCout(const unsigned int &decimal)
{
	std::cout << "decimal: " << decimal << std::endl;
	std::cout << "binary: ";

	for (int i = bitSize<unsigned int>() - 1; i >= 0; i--)
	{
		(decimal >> i & 1) ? std::cout << "1" : std::cout << "0";
		if (i % 8 == 0)
			std::cout << ' ';
	}
	std::cout << std::endl;
	
}
