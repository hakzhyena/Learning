#include "Conversion.h"


void Conversion::writeDecimalToCout(const std::string &binary)
{
	unsigned int decimal = 0, placeValue = 1;
	std::cout << "binary: " << binary << std::endl;
	for (int i = binary.size() - 1; i >= 0; i--) 
	{
		decimal += (binary[i] - '0') * placeValue;
		placeValue *= 2;
	}
	std::cout << "decimal: " << decimal << std::endl;
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
