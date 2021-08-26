#include <iostream>
#include "Animal.h"
Animal::Animal() 
{

}
Animal::Animal(const std::string& sound, const std::string &name) :_sound(sound), _name(name)
{
}
Animal::Animal(const Animal &rhs) 
{
	if (this != &rhs) //make sure it's not same object
	{
		_sound = rhs._sound;
		_name = "_clone " + rhs._name;
	}
		
}
Animal& Animal::operator=(const Animal& rhs) 
{
	if (this != &rhs) //make sure it's not same object
	{
		_sound = rhs._sound;
		_name = "_clone " + rhs._name;
	}
		
	return *this;
}
std::string Animal::getSound() 
{
	return _sound;
}
std::string Animal::getName() 
{
	return _name;
}
Animal::~Animal() 
{
	std::cout << "destructor of " << this->getName() << std::endl;
}