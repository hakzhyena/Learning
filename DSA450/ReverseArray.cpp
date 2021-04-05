
#include <iostream>
#include <string>

std::string reverseWord(std::string str) 
{
    std::string reverseString;
    if (str.empty()) 
    {
        return "";
    }
    if (str.length() > 10000) 
    {
        return "";
    }
    for (int i = str.length() - 1; i >= 0; i--) 
    {
        reverseString += str[i];
    }
    return reverseString;
}
int main()
{
    std::cout << reverseWord("Geeks");
}

