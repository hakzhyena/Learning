#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<string> split_string(string);

/*
* s - start of house
* t - end of house
* a - apple tree reference
* b - orange tree reference
* apples - number of apples
* oranges - number of oranges
*/
// Complete the countApplesAndOranges function below.
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) 
{
    int inApples = 0, inOranges = 0;
    for (int i = 0; i < (signed int)apples.size(); i++) 
    {
        if (apples[i] <= 0) //if apples[i] falls on or left of tree no need to calculate
            continue;
        if (((a + apples[i]) >= s) && ((a + apples[i]) <= t)) // if tree + d is in range of house
        {
            inApples++;
        }
    }
    for (int i = 0; i < (signed int)oranges.size(); i++)
    {
        if (oranges[i] >= 0) //if oranges[i] falls on or right of tree no need to calculate
            continue;
        if (((b - abs(oranges[i])) <= t) && (b - abs(oranges[i])) >= s) 
        {
            inOranges++;
        }
    }
    cout << inApples << endl << inOranges << endl;
}

int main1()
{
    string st_temp;
    getline(cin, st_temp);

    vector<string> st = split_string(st_temp);

    int s = stoi(st[0]);

    int t = stoi(st[1]);

    string ab_temp;
    getline(cin, ab_temp);

    vector<string> ab = split_string(ab_temp);

    int a = stoi(ab[0]);

    int b = stoi(ab[1]);

    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string apples_temp_temp;
    getline(cin, apples_temp_temp);

    vector<string> apples_temp = split_string(apples_temp_temp);

    vector<int> apples(m);

    for (int i = 0; i < m; i++) {
        int apples_item = stoi(apples_temp[i]);

        apples[i] = apples_item;
    }

    string oranges_temp_temp;
    getline(cin, oranges_temp_temp);

    vector<string> oranges_temp = split_string(oranges_temp_temp);

    vector<int> oranges(n);

    for (int i = 0; i < n; i++) {
        int oranges_item = stoi(oranges_temp[i]);

        oranges[i] = oranges_item;
    }

    countApplesAndOranges(s, t, a, b, apples, oranges);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
