#include <iostream>

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
int main() 
{
	int A = 4; //for input 11
	std::cout << countBitsUptoA(A);
}