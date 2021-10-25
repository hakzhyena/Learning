#include <iostream>
#include <vector>
#include "ImplementationDefined.h"
#include "StructvsClass.h"
#include "SimpleClass.h"
#include "Animal.h"
#include "Conversion.h"
#include "MaxValue.h"
void vecReverse(std::vector<int> &A) 
{
    int n = A.size();
    int mid = n / 2;
    for (int i = 0, j = n - 1; i < mid; i++, j--) 
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
std::vector<int> plusOne(std::vector<int>& A) 
{
    int tempResult = 0;
    int carry = 0;
    int n = A.size();
    std::vector<int> B = A;
    vecReverse(B);
    tempResult = B[0] + 1;
    carry = tempResult > 9 ? 1 : 0;
    B[0] = tempResult % 10;
    for (int i = 1; i < n && carry; i++) 
    {
        tempResult = B[i] + carry;
        carry = tempResult > 9 ? 1 : 0;
        B[i] = tempResult % 10;
    }
    if (carry)
        B.push_back(1);
    while (!B.empty() && B.back() == 0) 
    {
        B.pop_back();
    }
    vecReverse(B);
    return B;
}
std::vector<std::vector<int>> multipleLeftRotate(std::vector<int>& A, std::vector<int>& B) 
{
    int newIndex = 0;
    std::vector<std::vector<int>> C(B.size(),std::vector<int>(A.size()));
    for (int i = 0; i < B.size(); i++) 
    {
        for(int j = 0; j < A.size(); j++)
        {
            newIndex = j - B[i] % A.size();
            if (newIndex < 0)
                newIndex += A.size();
            C[i][newIndex] = A[j];
        }
    }
    return C;
}
std::vector<int> mulPrevAndNext(std::vector<int> &A)
{
    int n = A.size();
    std::vector<int> output(n);
    if (n == 1)
        return A;
    output[0] = A[0] * A[1];
    output[n - 1] = A[n - 1] * A[n - 2];
    for (int i = 1; i < n - 1; i++) 
    {
        output[i] = A[i - 1] * A[i + 1];
    }
    return output;
}
std::vector <std::vector<int>> PascalsTriangle(int A) 
{
    std::vector <std::vector<int>> output(A, std::vector<int>(A, 0));
    output[0][0] = 1;
    if (A == 1)
        return  output;
    output[1][0] = output[1][1] = 1;
    if (A == 2)
        return output;
    for (int i = 2; i < A; i++)
    {
        output[i][0] = 1;
    }
    for (int i = 2; i < A; i++) 
    {
        int j = 1;
        for (; j < i; j++) 
        {
            output[i][j] = output[i - 1][j] + output[i - 1][j - 1];
        }
        output[i][j] = 1;
    }
    return output;
}

std::vector < std::vector<int>> genereateSquareSpiralMatrix(int A) 
{
    if (A == 0) 
    {
        std::vector < std::vector<int>> output;
        return output;
    }
    std::vector < std::vector<int>> output (A,std::vector<int>(A,0));
    int i = 0, j = 0, dir = 0, currentValue = 1;
    while (currentValue <= A * A) 
    {
        output[i][j] = currentValue;
        currentValue++;
        if (dir == 0) 
        {
            j++;
            if (j == A || output[i][j] != 0) 
            {
                j--;
                dir = 1;
                i++;
            }
        }
        else if (dir == 1) 
        {
            i++;
            if (i == A || output[i][j] != 0) 
            {
                i--;
                dir = 2;
                j--;
            }
        }
        else if (dir == 2) 
        {
            j--;
            if (j < 0 || output[i][j] != 0) 
            {
                j++;
                dir = 3;
                i--;
            }
        }
        else if (dir == 3) 
        {
            i--;
            if (i < 0 || output[i][j] != 0)
            {
                i++;
                dir = 0;
                j++;
            }
        }
    }
    return output;
}
bool isPrime(int input)
{
    if (input < 2)
        return false;
    for (int i = 2; i <= sqrt(input); i++)
    {
        if (input % i == 0)
            return false;
    }
    return true;
}

int primalPowerOfArray(std::vector<int>& A)
{
    int count = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (isPrime(A[i]))
            count++;
    }
    return count;
}
void swap(int& A, int& B) 
{
    int temp = A;
    A = B;
    B = A;
}
void swampWithoutTemp(int& A, int& B) 
{
    A = A + B; // A has both A and B
    B = A - B; // B has A now
    A = A - B; // A has B now
}

void transposeMatrix(std::vector <std::vector<int>> &A) 
{
    int N = A.size();
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            swampWithoutTemp(A[i][j], A[j][i]);
        }
    }
}

void testDefaultMemberAccess() 
{
    Intro introToBook;
    Index indexOfBook;
    //std::cout << introToBook.length; //throws compilation error since members are private by default in class
    std::cout << indexOfBook.totalTopics; //accessible outside struct because members are public by default
}
void testSimpleClass() 
{
    SimpleClass object1, object2;
    object1.set(12);// this will set 12 to value in object1
    std::cout << "value was set using set() " << object1.get() << std::endl;
    std::cout << "member initialization available since C++11, object value is: " << object2.get() << std::endl;
    const SimpleClass object3;
    //Note that it is better to mark a member function as const if it doesn't modify the object because a const and non const can call
    //that member function. Note that a const object can't call non const member function as expected since compiler has to maintain
    //const-ness of the object. At the same time if a non-const/mutable version is available, that will be called for non-const objects.
    std::cout << object3.get() << std::endl; 
}
void constructAndDestrctors() 
{
    Animal a; //default constructor, has member intialized values
    std::cout << "a's Name: " << a.getName() << '\t' << "a's sound: " << a.getSound() << std::endl;
    Animal b("bow bow","Dog"); //parameterized constructor
    std::cout << "b's Name: " << b.getName() << '\t' << "b's sound: " << b.getSound() << std::endl;
    Animal c(b); // copy constructor
    std::cout << "c's Name: " << c.getName() << '\t' << "c's sound: " << c.getSound() << std::endl;
    Animal d; // default constructor
    // copy assignment operator
    d = a = c; //if copy assignment operator doesn't return Class& we can't chain these assignments as we will get the following error:
    //binary '=':no operator found which takes a right-hand operator of type 'void'
    std::cout << "a's Name: " << a.getName() << '\t' << "a's sound: " << a.getSound() << std::endl;
    std::cout << "d's Name: " << d.getName() << '\t' << "d's sound: " << d.getSound() << std::endl;
    //destruction happens in the reverse order construction
}
void numbersAndBitManipulation() 
{
    Conversion conversion;
    //conversion.writeBinaryToCout(1073741824);
    conversion.writeBinaryToCout(2147483649);
    //conversion.writeDecimalToCout("100100");
    //conversion.writeDecimalToCout("1100100");
}

std::string addBinary(std::string A, std::string B) {

    std::size_t asize = A.size();
    std::size_t bsize = B.size();
    std::string result;
    int carry = 0;
    int iterations = 0;
    //Append leading zeroes based on which string is larger
    if (asize > bsize)
    {
        result = std::string(asize + 1, '0');
        B = std::string(asize - bsize, '0').append(B);
        iterations = asize;
    }
    else if (bsize > asize)
    {
        result = std::string(bsize + 1, '0');
        A = std::string(bsize - asize, '0').append(A);
        iterations = bsize;
    }
    else if(asize == bsize)
    {
        result = std::string(asize + 1, '0');
        iterations = asize;
    }
    for (int i = iterations - 1; i >= 0; i--) 
    {
        int addition = (A[i] - '0') + (B[i] - '0') + carry;
        if (addition == 0) 
        {
            result[i + 1] = '0';
            carry = 0;
        }
        if (addition == 1)
        {
            result[i + 1] = '1';
            carry = 0;
        }
        if (addition == 2)
        {
            result[i + 1] = '0';
            carry = 1;
        }
        if (addition == 3)
        {
            result[i + 1] = '1';
            carry = 1;
        }
    }
    if (carry == 1)
        result[0] = '1';
    else
        result.erase(0,1);

    return result;
}
int setBits(int A)
{
    int result = 0;
    for (int i = (sizeof(A) * 8) - 2; i >= 0; i--)
    {
        if ((A >> i) & 1)
            result++;
    }
    return result;
}
int solve(int A) {

    long long total = 0;

    for (int i = 1; i < A; i++)
        total += setBits(i);

    return total % 1000000007;
}

void printArray(int arr[], int n, int s) 
{
    if (s == n) return;
    std::cout << arr[n];
    printArray(arr, n, s+1);

}

void subArray(int A[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            std::cout << "{";
            for (int k = i; k <= j; k++)
            {
                std::cout << A[k];
            }
            std::cout << "}";
        }
        std::cout << std::endl;
    }
}
int goodPair(std::vector<int>& A, int B) 
{
        for (int i = 0; i < A.size() - 1; i++) 
        {
            for (int j = i+1; j < A.size(); j++) 
            {
                if (A[i] + A[j] == B)
                    return 1;
            }
        }
    return 0;
}
std::vector<std::string> fizzBuzz(int A) 
{
    std::vector<std::string> output;
    for (int i = 0; i < A; i++) 
    {
        if ((i+1) % 3 == 0 && (i + 1) % 5 == 0)
            output.push_back("FizzBuzz");
        else if ((i + 1) % 3 == 0)
            output.push_back("Fizz");
        else if ((i + 1) % 5 == 0)
            output.push_back("Buzz");
        else
            output.push_back(std::to_string(i+1));
    }
    return output;
}

int oddEvenSubStringCount(std::vector<int> &A) 
{
    int count = 0;
    bool findOddNext = false;
    if (A.size() >= 1)
        count = 1;
    else
        return 0;
    if (A[0] % 2 == 0)
        findOddNext = true;
    
    for (int i = 1; i < A.size(); i++) 
    {
        if (findOddNext == true) 
        {
            if (A[i] % 2 == 1) 
            {
                count++;
                findOddNext = false;
            }
        }
        else 
        {
            if (A[i] % 2 == 0) 
            {
                count++;
                findOddNext = true;
            }
        }
    }
    return count;
}

void columnSwap(std::vector<std::vector<int>> &A) 
{
    int N = A.size();
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N/2; j++) 
        {
            swampWithoutTemp(A[i][j], A[i][N - j - 1]);
        }
    }
}

void rotate(std::vector < std::vector<int>>& A) 
{
    transposeMatrix(A);
    columnSwap(A);
}
std::vector<std::vector<int>> antiDiagonals(std::vector<std::vector<int>>& A) 
{
    int totalRows =  A.size();
    int totalColumns = totalRows; //square matrix
    int totalOutputRows = 2 * totalRows - 1;
    std::vector<std::vector<int>> output(totalOutputRows);
    //Go through each element
    for (int i = 0; i < totalRows; i++) 
    {
        for (int j = 0; j < totalColumns; j++) 
        {
            output[i + j].push_back(A[i][j]);
        }
    }
    for (int i = 0; i < totalOutputRows; i++) 
    {
        int toFill = totalColumns - output[i].size() - 1;
        for (int j = toFill; j > 0; j--) 
        {
            output[i].push_back(0);
        }
    }
    return output;
}
int maxOnes(std::vector<std::vector<int>> &A) 
{
    int totalRows = A.size();
    int outputRow = 0;
    if (totalRows == 0)
        return -1;
    if (totalRows == 1)
        return 0;
    int totalCols = A[0].size();
    for (int i = 0, j = totalCols - 1; i < totalRows; i++) 
    {
        while (A[i][j] == 1)
        {
            outputRow = i;
            j--;
        }
        if (j == -1)
            break;
    }
    return outputRow;
}
int FindNumber(std::vector<std::vector<int>>& A, int B) 
{
    int totalRows = A.size();
    if (totalRows == 0)
        return -1;
    int totalCols = A[0].size();
    int i = 0, j = totalCols - 1;
    while (i < totalRows && j >= 0) 
    {
        if (B == A[i][j])
        {
            int finalJ = j;
            j--;
            while (B == A[i][j]) 
            {
                finalJ = j;
                j--;
            }
            return (i + 1) * 1009 + finalJ + 1;
        }
            
        else if (B > A[i][j])
            i++;
        else
            j--;
    }
    return -1;
}
int main()
{
    
    std::vector<std::vector<int>> A = { 
        {1,2,3},
        {4,5,6},
        {7,8,9}

    };
    int rowWithMaxOnes = FindNumber(A,2);


}
std::vector<int> rotate(std::vector<int> &A, int B) 
{
    std::vector<int> output;
    int n = A.size();
    output.reserve(n);
    int newIndex = 0;
    for (int i = 0; i < n; i++) 
    {
        newIndex = (i + B) % n;
        output[newIndex] = A[i];
    }
    return output;
}

int main2() {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int n, input, B;
    std::cin >> n;
    std::vector<int> A;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        A.push_back(input);
    }
    std::cin >> B;
    std::vector<int> output = rotate(A, B);
    for (int i = 0; i < n; i++)
    {
        std::cout << output[i] << ' ';
    }
    return 0;
}