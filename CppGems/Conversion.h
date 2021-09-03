#pragma once
#include "CommonHeaders.h"
#include <climits> //CHAR_BIT
#include <string>
class Conversion
{
	int decimal = 10;
public:	
	void writeBinaryToCout(const unsigned int &decimal);
	void writeDecimalToCout(const std::string &binary);
};

