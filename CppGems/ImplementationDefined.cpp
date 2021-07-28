#include <iostream>
#include "ImplementationDefined.h"

void ImplementationDefined::TestImplementationDefinedBehaviour()
{
	std::cout << "Size of character is " << sizeof(char)  << ((sizeof(char) == 1) ? " byte" : " bytes");
	std::cout << std::endl;
	unsigned char c1 = 64; //well-defined because char must be atleast 1 byte
	std::cout << "c1 value is: " << c1 << std::endl;
	unsigned char c2 = 1256;
	std::cout << "c2 value is: " << c2 << " as defined by the implementation" << std::endl; //c2 has truncated value - LSB
	static_assert(1 <= sizeof(char) , "size of (char) is too small"); // compile time error message introduced in C++ 11.
}
