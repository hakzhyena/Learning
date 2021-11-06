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
int closestMinMax(std::vector<int>& A) 
{
	int n = A.size();
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int min = INT_MAX, min_i = -1, max = -1, max_i = -1;
	for (int i = 0; i < n; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
			min_i = i;
		}
		if (A[i] > max)
		{
			max = A[i];
			max_i = i;
		}
	}
	int smallest_distance = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == min)
		{
			min_i = i;
			int temp_result = (abs(max_i - min_i) + 1);
			if (temp_result < smallest_distance)
				smallest_distance = temp_result;
		}
		if (A[i] == max)
		{
			max_i = i;
			int temp_result = (abs(max_i - min_i) + 1);
			if (temp_result < smallest_distance)
				smallest_distance = temp_result;
		}
	}
	return smallest_distance;
}
int consecutiveOnesLength(std::string &A) 
{
	
	int flips = 0;
	int ans = 0;
	int i = 0, j = 0;
	int n = A.size();
	int total_ones = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == '1')
			total_ones++;
	}

	while (i < n)
	{
		if (A[i] == '0')
		{
			flips++;
		}
		while (flips > 1)
		{
			if (A[j] == '0')
				flips--;
			j++;
		}
		ans = std::max(ans, i - j + 1);
		i++;
	}
	return std::min(ans, total_ones);
}
int main() 
{
	std::string input = "010100110101";
	int result = consecutiveOnesLength(input);
	std::cout << result << std::endl;
}