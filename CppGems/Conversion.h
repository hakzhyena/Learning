#pragma once
#include "CommonHeaders.h"
#include <climits> //CHAR_BIT
class Conversion
{
	int decimal = 10;
public:	
	void writeBinaryToCout(const unsigned int &decimal);
	void writeDecimalToCout();
};

