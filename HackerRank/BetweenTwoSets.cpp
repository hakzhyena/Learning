#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void countBetweenTwoSets(int n, int m,vector<int> a, vector<int> b) 
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool flagA = true, flagB = true;
    int count = 0;
    for (int i = a[n - 1]; i <= b[0]; i++) 
    {
        flagA = true;
        flagB = true;
        for (int j = 0; j < a.size(); j++) 
        {
            if (i % a[j] != 0) 
            {
                flagA = false;
                break;
            }
        }
        if (flagA == true) 
        {
            for (int k = 0; k < b.size(); k++) 
            {
                if (b[k] % i != 0) 
                {
                    flagB = false;
                    break;
                }
            }
        }
        if (flagA == true && flagB == true) 
        {
            count++;
        }
    }
    cout << count;
}
//credit to hackerrank for split_string!
static vector<string> split_string(string input_string) {
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
int main() 
{
    //scan n and m
	string nm_str;
	getline(cin, nm_str);
	vector<string> nm = split_string(nm_str);
    int n = stoi(nm[0]);
    int m = stoi(nm[1]);
    //scan n elements
    string n_str;
    getline(cin, n_str);
    vector<string> a_str = split_string(n_str);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int a_item = stoi(a_str[i]);
        a[i] = a_item;
    }
    //scan m elements
    string m_str;
    getline(cin, m_str);
    vector<string> b_str = split_string(m_str);
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        int b_item = stoi(b_str[i]);
        b[i] = b_item;
    }
    countBetweenTwoSets(n, m, a, b);
}