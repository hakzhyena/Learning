#include <iostream>
#include <array>
int main() 
{
	//std::array represents arrays of fixed size unlike dynamically sized array of type std::vector
	//dynamic memory allocation has computational cycle overheads and risks memory fragmentation
	//Unlike std::vector which has 24 bytes of overhead std::array doesn't have any overhead
	std::array<int, 5> arr1 = {1,1,1,1,1};
	
	std::array<int, 4> arr2 = { 0,1,2,3};
	auto arr3 = arr2;
	auto arr4(arr1);
	std::array<int, 5> arr5 = {};
	arr5 = arr4; //supports copy of elements in safe way unlike plain C style arrays where we need to worry about 
	             // memcpy buffer overruns
	int value = arr5[2]; //access elements with familiar subscript operator
	value = arr5[5]; //however like in case std::vector subscript operator doesn't do bounds checking
	value = arr5.at(5);// and at is better if you want that.
	if(arr2.front() == 0 && arr2.back() == 3) 
		std::cout << "Same like vector";
	if (arr2.max_size() == arr2.size())
		std::cout << "Because size of array is constant";
	if(arr2.empty())// is kind a self explainatory that since there is no 'resizing' of array invoved
		std::cout << "Welp, that's weird"; // unles array is sized to be zero like std::array<int,0> a; it's not gonna return false

	

}