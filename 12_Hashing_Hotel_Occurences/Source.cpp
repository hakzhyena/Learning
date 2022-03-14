#include <vector>
#include <iostream>
#include <unordered_set>
std::vector<int> HotelOccurences(std::vector<int>& A) 
{
	std::vector<int> output;
	std::unordered_set<int> processor;
	for (auto it = A.rbegin();  it != A.rend(); it++)
	{
		processor.insert(*it);
	}
	for (const auto it = processor.rbegin(); : processor)
	{
		output.push_back(i);
	}
	return output;
}
int main()
{
	std::vector<int> input = std::vector<int>{ 1, 2, 3, 2, 5, 3, 2, 4 };
	std::vector<int> output = HotelOccurences(input);
	for (const auto i : output)
		std::cout << i ;

}