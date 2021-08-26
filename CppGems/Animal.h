#pragma once
#include <string>
class Animal
{
	std::string _name = "Animal";
	std::string _sound = "default sound";
public:
	Animal();//explicit default constructor
	Animal(const std::string &sound, const std::string &name);//explict constructor with arg
	Animal(const Animal &rhs);//explicit copy constructor
	//* if you pass by value to copy constructor, you get the error - 'Animal': illegal copy constructor: first parameter must not be
	// a 'Animal'
	Animal& operator= (const Animal& rhs);//explicity copy operator
	~Animal();
	std::string getSound();
	std::string getName();
};

