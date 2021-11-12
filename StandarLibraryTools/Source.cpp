#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <array>
int stdarrayExperiments()
{
	//std::array represents arrays of fixed size unlike dynamically sized array of type std::vector
	//dynamic memory allocation has computational cycle overheads and risks memory fragmentation
	//Unlike std::vector which has 24 bytes of overhead std::array doesn't have any overhead
	std::array<int, 5> arr1 = { 1,1,1,1,1 };

	std::array<int, 4> arr2 = { 0,1,2,3 };
	auto arr3 = arr2;
	auto arr4(arr1);
	std::array<int, 5> arr5 = {};
	arr5 = arr4; //supports copy of elements in safe way unlike plain C style arrays where we need to worry about 
				 // memcpy buffer overruns
	int value = arr5[2]; //access elements with familiar subscript operator
	value = arr5[5]; //however like in case std::vector subscript operator doesn't do bounds checking
	value = arr5.at(5);// and at is better if you want that.
	if (arr2.front() == 0 && arr2.back() == 3)
		std::cout << "Same like vector";
	if (arr2.max_size() == arr2.size())
		std::cout << "Because size of array is constant";
	if (arr2.empty())// is kind a self explainatory that since there is no 'resizing' of array invoved
		std::cout << "Welp, that's weird"; // unles array is sized to be zero like std::array<int,0> a; it's not gonna return false
	return 0;
}
/*
* std::vector - container type for dynamic arrays - those that can grow or shrink during runtime
* templated container class
* typically allocates memory on heap
* abstracts memory management as it grows and shrinks if the elements are added or removed
* tracks your number of elements
* tracks your amount of memory
* inserting elements into the middle of an array is simplified - no need to manually move around
* on out of scope std::vector memory will be distructed and freed automatically - no memory leaks
* vector is guranteed to be contiguous
*/

//API with C-style buffer interface
void fun(int* vecFirstElementAddr, int* vecData, size_t size)
{
	if (vecFirstElementAddr == vecData)
	{
		std::cout << "accessing the address of first element is fine either way" << std::endl;
	}
	else
	{
		std::cout << "Hmm, weird!" << std::endl;
	}
}
void fun1(int* staticArray, int* toFirstElement)
{
	if (staticArray == toFirstElement)
	{
		std::cout << "mentioning name of array is as good as address of first element" << std::endl;
	}
}
int vectorExperiments()
{
	//empty std::vector that holds ints
	std::vector<int> v1;
	//vector with initial values of size of length of initializer list
	std::vector<int> v2 = { -3, 2, 0, 4, 1 };
	//copy elements of vector v2 to v1. Simple enough, no need of memcpy!
	v1 = v2;
	//create new vector and initialize with the values as existing vector
	auto v3(v1);
	std::cout << v3.front() << std::endl;//accessing the first element of vector - v3[0]
	std::cout << v3.back() << std::endl;//accessing the last element of vector - v3[length - 1]
	std::cout << v3.at(3) << std::endl;//checks bounds - throws exception if out-of-bounds
	std::cout << v3[3] << std::endl;//faster access at risk of seg fault, un defined behaviour
	//std::cout << v3.at(10) << std::endl;//abort() has been called
	//std::cout << v3[10] << std::endl; // vector subscript out of range
	fun(&v3[0], v3.data(), v3.size());
	int staticArray[10] = { 0 };
	fun1(staticArray, &staticArray[0]); //you can't do the same with vector
	v3.push_back(10);// add 10 to the end - construct first add to container next
	std::cout << v3.back() << std::endl;
	v3.emplace_back(11);// in place construction
	std::cout << v3.back() << std::endl;
	v3.insert(v3.begin(), -2); //insert at the location pointed to by iterator, in this case 0 - doesn't mean replace though
	v3.insert(v3.begin() + 3, 5); // insert at 0 + 3 and right move the elements from 3.
	v3.insert(v3.end(), 10); //insert at length - meaning v3.end() points to past-the-end because you can't access/deference the size either in static array
							 // the usual syntax for traversing is for(int i = 0; i < len; i++) - meaning no accessing arr[i] here either
	v3.emplace(v3.end(), 100);// same as insert except in place construct
	v3.erase(v3.end() - 1); // supply the iterator that points to the element to be removed
	v3.erase(v3.end() - 1); // removed last elements. Note that it's end() - 1 not end(). 
	size_t size = v3.size(); //size is number of elements in the vector
	v3.pop_back(); //remove last element
	v3.clear(); // remove all elements from the vector, but capacity is at previous allocation level
	size = v3.size(); // now the size is 0
	size_t capacity = v3.capacity(); //size of currently allocated storage space for the vector in terms of elements
	size_t max_size = v3.max_size(); // maximum elements vector can hold
	v3.reserve(200); // Reserve capacity for atleast 200 elements, note that reallocations are costly
					 // in terms of performance, use reserve to make single large allocation with
					 // keeping max elements in the mind so that frequent reallocations don't need to occur
	capacity = v3.capacity(); //size of currently allocated storage space for the vector in terms of elements
	v3.push_back(0);//add few elements
	v3.push_back(1);//add few more elements
	v3.shrink_to_fit();//shrink the capacity to size
	v3.resize(5);//extend size to 5 from 2 - note that remaining 3 elements are zero initialized
				 // note that resize adds elements and increses size where as reserve updates capacity but no size
	v3.resize(10, -1); //exten size to 10 - assign remaining elements with -1
	v3.resize(2); // shrink and keep only initial two elements - remove the remaining - note capacity remains previously allocated
	v3.clear(); // = v3.resize(0) 
	if (v3.empty() == (v3.size() == 0)) // note that v3.empty() basically checks v3.size() == 0
		std::cout << "no elements";
	v3.reserve(5);// if you're reserving lesser number than capacity it retains the capacity.
	for (int i = 0; i < 5; i++)
	{
		v3.push_back(i);
	}
	//more convinent loop to iterate through vector
	std::cout << std::endl;
	for (const auto& t : v3)
		std::cout << t << " ";
	std::cout << std::endl;

	std::vector<int> v4;
	v4.reserve(1);
	v4.push_back(0);
	v4.push_back(1); // after reserve if you go overboard, reallocation occurs and so capacity increases

	// random access - O(1)
	// insertion and removal at end - O(1)
	// insertion and removal at other places - O(n)
	// 24 bytes of overhead for storage
	return 0;
}
void fun(const std::string& s)
{

}
int stringExperiments()
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
	std::cout << filledwithNChars << "After move myName is:" << myName << std::endl;
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
	filledwithNChars.erase(filledwithNChars.begin() + 4);// pass the iterator of the char to be deleted
	std::cout << "After erasing char at index 3: " << filledwithNChars << std::endl;
	std::cout << "substring of filledwithNChars from 2 nd index 2 inclusive chars: " << filledwithNChars.substr(2, 2) << std::endl;
	std::cout << "find h in: " << filledwithNChars << " " << filledwithNChars.find('h') << std::endl;
	//send/receiving strings by value involves a copy, so if you don't want to modify them in function
	// receive them as const std::string &
	fun(filledwithNChars);

	return 0;
}
//Use unordered_set for following reasons:
//1) You want a data structure that stores unique elements. 
//2) If you are inserting a repeating element, insert gives you error and doesn't go though.
bool uniqueValues(std::vector<int> &A)
{
	std::unordered_set<int> uniqueElements;
	int length = A.size();
	for (size_t i = 0; i < length; i++)
	{
		if (uniqueElements.insert(A[i]).second == false)
			return false;
	}
	return true;
}

int main() 
{
	std::vector<int> values{1,2,3,4,5};
	std::cout << uniqueValues(values);
}