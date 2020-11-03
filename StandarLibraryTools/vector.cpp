#include <vector>
#include <iostream>
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
void fun(int *vecFirstElementAddr, int *vecData, size_t size) 
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
void fun1(int *staticArray, int *toFirstElement) 
{
	if (staticArray == toFirstElement) 
	{
		std::cout << "mentioning name of array is as good as address of first element" << std::endl;
	}
}
int main() 
{
	//empty std::vector that holds ints
	std::vector<int> v1;
	//vector with initial values of size of length of initializer list
	std::vector<int> v2 = {-3, 2, 0, 4, 1};
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
	int staticArray[10] = {0};
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
	v3.reserve(5);
	for (int i = 0; i < 5; i++) 
	{
		v3.push_back(i);
	}
	//more convinent loop to iterate through vector
	std::cout << std::endl;
	for (const auto& t : v3)
		std::cout << t << " ";
	std::cout << std::endl;
	// random access - O(1)
	// insertion and removal at end - O(1)
	// insertion and removal at other places - O(n)
	// 24 bytes of overhead for storage
}