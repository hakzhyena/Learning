#include <iostream>
#include <vector>
#include <algorithm>
int main() 
{
	using namespace std;
	vector<int> A;
	for (int i = 10; i > 0; i--) 
	{
		A.push_back(i);
	}
	cout << "Before sorting the vector" << endl;
	for (auto i : A)
	{
		cout << i << ' ';
	}
	cout << endl;
	sort(A.begin(), A.end());//This uses quick sort - O(nlogn)
	cout << "After sorting the vector" << endl;
	for (auto i : A)
	{
		cout << i << ' ';
	}
	cout << endl;

}