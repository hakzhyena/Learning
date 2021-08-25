#include <iostream>

#include "ImplementationDefined.h"
#include "StructvsClass.h"
#include "SimpleClass.h"
void testDefaultMemberAccess() 
{
    Intro introToBook;
    Index indexOfBook;
    //std::cout << introToBook.length; //throws compilation error since members are private by default in class
    std::cout << indexOfBook.totalTopics; //accessible outside struct because members are public by default
}
int main()
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
