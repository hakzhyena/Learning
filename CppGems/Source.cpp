#include <iostream>

#include "ImplementationDefined.h"
#include "StructvsClass.h"
void testDefaultMemberAccess() 
{
    Intro introToBook;
    Index indexOfBook;
    std::cout << introToBook.length; //throws compilation error since members are private by default in class
    std::cout << indexOfBook.totalTopics; //accessible outside struct because members are public by default
}
int main()
{
    testDefaultMemberAccess();
}
