#include <iostream>
#include <vector>
using namespace std;
int bthSmallestWithMinimumSwaps(const vector<int> &A, int B) 
{
	vector<int> CopyOfA = A; //need to make copy because A is const!

	for (int i = 0; i < B; i++) 
	{
		int index = i; int minIndex = -1;	int min = INT_MAX;
		for (vector<int>::iterator it = CopyOfA.begin() + i; it !=  CopyOfA.end(); it++)
		{
			if (*it < min)
			{
				min = *it;
				minIndex = index;
			}
			index++;
		}
		//swap when min index is updated
		if (minIndex != -1) 
		{
			int temp = CopyOfA[minIndex];
			CopyOfA[minIndex] = CopyOfA[i];
			CopyOfA[i] = temp;
		}
		
	}
	return CopyOfA[static_cast<std::vector<int, std::allocator<int>>::size_type>(B) - 1];

	
}
int main() 
{
	vector<int> input{ 1,2 };
	cout << bthSmallestWithMinimumSwaps(input,2);
}
