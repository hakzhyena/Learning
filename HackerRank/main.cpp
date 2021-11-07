#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
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
int findBInSortedMatrix(std::vector<std::vector<int> >& A, int B) 
{
	int i = 0;
	int n = A.size();
	int j = A[i].size() - 1;
	bool insideArray = (i > n || j < 0) ? false : true;
	while (i != n && j >= 0)
	{
		if (A[i][j] < B)
		{
			i++;
		}else
		if (A[i][j] > B)
		{
			j--;
		}else
		if (A[i][j] == B)
		{
			int temp = j;
			while (A[i][j] == B)
			{
				temp = j;
				j--;
				if (j < 0)
					break;
			}
			return ((i+1)* 1009 + temp+1);
		}
		
	} 
		return -1;
}
std::vector<std::vector<int>> patternPrinting(int A)
{
	std::vector<std::vector<int>> output(A,std::vector<int>(A,0));
	for (int i = 0; i < A; i++) 
	{
		for (int j = 0, idx = A-1; j < i + 1; j++,idx--) 
		{
			output[i][idx]=  j + 1;
		}
	}
	return output;
}

std::vector<int> repeatingNumbers(std::vector<int>& A, std::vector<int>& B) 
{
	std::vector<int>::iterator it1 = A.begin();
	std::vector<int>::iterator it2 = B.begin();
	std::vector<int>::iterator itend1 = A.end();
	std::vector<int>::iterator itend2 = B.end();
	std::vector<int> result;
	while (it1 != itend1 && it2 != itend2) 
	{
		if (*it1 < *it2)
		{
			it1++;
		}else if(*it1 > *it2) 
		{
			it2++;
		}
		else
		{
			result.push_back(*it1);
			it1++;
			it2++;
		}
	}
	return result;
}

std::vector<int> TwoOutOfThree(std::vector<int>& A, std::vector<int>& B, std::vector<int> &C) 
{
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	std::sort(C.begin(), C.end());
	std::vector<int> output1 = repeatingNumbers(A, B);
	auto v = repeatingNumbers(A, C);
	output1.insert(output1.end(), v.begin(), v.end());
	v = repeatingNumbers(B, C);
	output1.insert(output1.end(), v.begin(), v.end());
	std::set<int> temp(output1.begin(), output1.end());
	output1.assign(temp.begin(), temp.end());
	std::sort(output1.begin(), output1.end());
	return output1;
}

int main()
{

	std::vector<int> A{ 4, 3, 2, 1 };
	std::vector<int> B{ 5, 6, 7, 8, 9 };
	std::vector<int> C{ 10, 11, 1 };
	TwoOutOfThree(A, B, C);
	return 0;

}