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

}