#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int CheckArithmeticProgression(vector<int>& A)
{
	sort(A.begin(), A.end(), greater<int>());

	if (A.size() == 1 || A.size() == 0)
		return 0;
	auto diff = A[0] - A[1];
	for (vector<int>::iterator it = A.begin() + 1; it != A.end(); it++) 
	{
		if ((it+ 1 < A.end()) && ( *it - *(it + 1) != diff))
			return 0;
	}
	return 1;
}
int main() 
{
	vector<int> input{ 3, 5, 1 };
	cout << CheckArithmeticProgression(input);
}