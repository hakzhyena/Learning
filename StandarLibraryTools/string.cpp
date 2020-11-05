#include <iostream>
#include <string>
void fun(const std::string &s) 
{

}
int main() 
{
	//C-style strings are char arrays terminated by a null character
	const char* str = "This is a string literal, not a char array you know because double quotes"; // Compiler
	                 //adds null character at end for string literals, you don't have to!
	//strlen, strcpy and strcat are provided by C standard library available in string.h, in C++ standard
	//library they are available at <cstring>. But note that they are require terminating null character 
	//-to process C style-strings.
	//Usual disadvantages of C style strings are a) they are not self aware of their size, so you need to use
	// strlen of O(n) complexity to find it.
	//b) if null character is not manually appended your string.h functions go out of bounds.
	//c) C-style strings are usually fixed size arrays ex: char str[256]; dynamically sized arrays must be
	// taken care of memory management by the programmer.
	//d) off by one bugs are common because progammer must space an extra byte for null char, where as 
	// strlen returns the size without including the size of null char!
	//std::string stores your underlying characters in a contiguous manner. c_str() returns you access to
	//this underlying buffer which is a pointer to null char terminated char array.
	std::string defString;
	std::cout << "Size of default string:" << defString.size() << std::endl;
	std::cout << "Capacity of default string:" << defString.capacity() << std::endl;
	std::string emptyString("");
	std::cout << "Size of empty string:" << emptyString.size() << std::endl;
	std::cout << "Capacity of empty string:" << emptyString.capacity() << std::endl;
	std::string myName("Harish");
	std::cout << "Size of myName string:" << myName.size() << std::endl;// note that size() returns length
	                                        // and that too without null char space
	std::cout << "Length of myName string:" << myName.length() << std::endl; // note that length() and size()
	                                        // are  synonyms here.
	std::cout << "Capacity of myName string:" << myName.capacity() << std::endl;
	std::string name2(myName); // you can initialize std::string with another string
	std::string name3(myName, 2); // initialize string from 2nd index of myName
	std::cout << name2 << std::endl;
	std::cout << name3 << std::endl;
	std::string filledwithNChars(10, 'H');
	std::cout << filledwithNChars << std::endl;
	filledwithNChars = myName; // copy assignement
	std::cout << filledwithNChars << std::endl;
	filledwithNChars = "string literal"; // string literal assignment
	std::cout << filledwithNChars << std::endl;
	filledwithNChars = std::move(myName); // move assignment - less expensive that copy assigment but 
	                                     //  from where you copy may become empty!
	std::cout << filledwithNChars <<"After move myName is:" <<myName << std::endl;
	if (myName == filledwithNChars) // use == operator for comparison, one of the operands need to be string
		std::cout << "strings match" << std::endl; // - meaning myName == "Test" is also fine when "Test" is
	                                               // - string literal
	else
		std::cout << "strings don't match" << std::endl;
	myName = "Test Name";
	if (filledwithNChars < "harish") //lexicographical ordering is ordering by ASCII values of characters
	{                                // - since captial letters come before small letters it returns that 
		                             // H is smaller than h
		std::cout << filledwithNChars << " " << "comes before " << "harish " << "lexicographically" << std::endl;
	}
	filledwithNChars.erase(filledwithNChars.begin()+4);// pass the iterator of the char to be deleted
	std::cout << "After erasing char at index 3: " << filledwithNChars << std::endl;
	std::cout << "substring of filledwithNChars from 2 nd index 2 inclusive chars: " << filledwithNChars.substr(2, 2) << std::endl;
	std::cout << "find h in: "<< filledwithNChars<< " " << filledwithNChars.find('h') << std::endl;
	//send/receiving strings by value involves a copy, so if you don't want to modify them in function
	// receive them as const std::string &
	fun(filledwithNChars);
	
	return 0;
}
