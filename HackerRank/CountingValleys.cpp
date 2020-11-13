#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) 
{
    int counter = 0;
    int index = 0;
    int valleys = 0;
    if (steps == 0 || steps == 1) 
    {
        return 0;
    }
    (path[0] == 'U') ? counter++ : counter--;
    for (std::string::iterator it = path.begin() + 1; it != path.end(); it++)
    {
        if (counter == 0)
        {
            if (path[index] == 'D')
                valleys++;
            index = it - path.begin();
        }
        (*it == 'U') ? counter++ : counter--;
    }
    if(counter == 0)
        if (path[index] == 'D')
            valleys++;
    return valleys;
}

int main()
{
    ofstream fout("C:\\source\\test1.txt");

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
