#include <iostream>
#include <vector>
int countBitsUptoA(int A) {
	long long result = 0;
	long long numOfPatternsMultipliedByBits = 0;
	long long remainderBits = 0;
	
	for (int i = 0; i < 32; i++)
	{
		numOfPatternsMultipliedByBits = ((static_cast<long long>(A) + 1) / (1LL << (i + 1))) * (1LL << i);
		if ((((static_cast<long long>(A) + 1) % (1LL << (i + 1))) - (1LL << i)) <= 0)
			remainderBits = 0;
		else
		remainderBits = (((static_cast<long long>(A) + 1)) % (1LL << (i + 1))) - (1LL << i);

		result += numOfPatternsMultipliedByBits + remainderBits;
	}

	return result %= 1000000007;
}
int subsequencesOfGivenString(std::string A) 
{
	int N = A.size();
	int64_t countOfGs = 0;
	int64_t countOfAGpairs = 0;
	for (int i = N - 1; i >= 0; i--) 
	{
		if (A[i] == 'G')
			countOfGs++;
		else if (A[i] == 'A')
			countOfAGpairs += countOfGs;
	}
	return countOfAGpairs % 1000000007;
}
int equality(std::vector<int>& A) {
	int N = A.size();
	int sum = 0;
	int maximumElement = 0;
	for (int i = 0; i < A.size(); i++) 
	{
		if (A[i] > maximumElement)
			maximumElement = A[i];
		sum += A[i];
	}
	return (maximumElement* N) - sum;
}

int main() 
{
	//int A = 4; //for input 11
	//std::cout << countBitsUptoA(A);
	//std::cout << subsequencesOfGivenString("ABCGAG");
	std::vector<int> input{2, 4, 1, 3, 2};
	std::cout << equality(input);
}