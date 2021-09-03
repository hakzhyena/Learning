#include <iostream>

#include "ImplementationDefined.h"
#include "StructvsClass.h"
#include "SimpleClass.h"
#include "Animal.h"
#include "Conversion.h"
void testDefaultMemberAccess() 
{
    Intro introToBook;
    Index indexOfBook;
    //std::cout << introToBook.length; //throws compilation error since members are private by default in class
    std::cout << indexOfBook.totalTopics; //accessible outside struct because members are public by default
}
void testSimpleClass() 
{
    SimpleClass object1, object2;
    object1.set(12);// this will set 12 to value in object1
    std::cout << "value was set using set() " << object1.get() << std::endl;
    std::cout << "member initialization available since C++11, object value is: " << object2.get() << std::endl;
    const SimpleClass object3;
    //Note that it is better to mark a member function as const if it doesn't modify the object because a const and non const can call
    //that member function. Note that a const object can't call non const member function as expected since compiler has to maintain
    //const-ness of the object. At the same time if a non-const/mutable version is available, that will be called for non-const objects.
    std::cout << object3.get() << std::endl; 
}
void constructAndDestrctors() 
{
    Animal a; //default constructor, has member intialized values
    std::cout << "a's Name: " << a.getName() << '\t' << "a's sound: " << a.getSound() << std::endl;
    Animal b("bow bow","Dog"); //parameterized constructor
    std::cout << "b's Name: " << b.getName() << '\t' << "b's sound: " << b.getSound() << std::endl;
    Animal c(b); // copy constructor
    std::cout << "c's Name: " << c.getName() << '\t' << "c's sound: " << c.getSound() << std::endl;
    Animal d; // default constructor
    // copy assignment operator
    d = a = c; //if copy assignment operator doesn't return Class& we can't chain these assignments as we will get the following error:
    //binary '=':no operator found which takes a right-hand operator of type 'void'
    std::cout << "a's Name: " << a.getName() << '\t' << "a's sound: " << a.getSound() << std::endl;
    std::cout << "d's Name: " << d.getName() << '\t' << "d's sound: " << d.getSound() << std::endl;
    //destruction happens in the reverse order construction
}
void numbersAndBitManipulation() 
{
    Conversion conversion;
    conversion.writeBinaryToCout(10);
}
int main()
{
    numbersAndBitManipulation();

}
