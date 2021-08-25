#include <iostream>
#include "SimpleClass.h"
int SimpleClass::get() const
{
	std::cout << "const get()" << std::endl;
	return value;
}

int SimpleClass::get()  
{
	std::cout << "Mutable get()" << std::endl;
	return value;
}
void SimpleClass::set(const int &a) 
{
	value = a;
}