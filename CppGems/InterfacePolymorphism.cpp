// CppGems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Base 
{
 
public:
    virtual void prepare() 
    {
        std::cout << "Class: Base" << std::endl;
    }
};

class Derived1 :public Base
{

public:
    virtual void prepare()
    {
        std::cout << "class: Derived1" << std::endl;
    }
};

class Derived2 : public Derived1
{
public:
    
};

class Derived3 : public Derived2
{
    virtual void prepare()
    {
        return Derived2::prepare();
    }
};

