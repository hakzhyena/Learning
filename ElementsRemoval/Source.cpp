#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int accumulate(vector<int> &A) 
{
	int sum = 0;
	for (auto i : A) 
	{
		sum += i;
	}
	return sum;
}
int ElementsRemoval(vector<int>& A) 
{
	sort(A.begin(), A.end());
	int cumulativeSum = 0;
	int index = A.size() - 1;
	while (A.size())
	{
		cumulativeSum += accumulate(A);
		A.erase(A.begin() + index);
		index--;
	}
	return cumulativeSum;
}

int main()
{
	vector<int> input{ 2, 1};
	cout << ElementsRemoval(input);
}