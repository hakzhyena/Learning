#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// Complete the birthday function below.
int birthday(vector<int> s, int d, int m) {
    int index = 0;
    int tempOut = 0;
    int result = 0;
    if (s.size() == 1 && m == 1 && d == s[0]) 
    {
        return 1;
    }
    for (int i = 0; i <= s.size() - m; i++) 
    {
        cout << endl;
        tempOut = 0;
        for (int j = 0; j < m; j++) 
        {
            tempOut += s[j + i];
            cout << j << "\t" << s[j+i] << "\t" << tempOut << endl;
        }
        if (tempOut == d)
            result++;
    }
    cout << endl << result;
    return result;
}

int main()
{
    ofstream fout("c:\\source\\test.txt");

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    string dm_temp;
    getline(cin, dm_temp);

    vector<string> dm = split(rtrim(dm_temp));

    int d = stoi(dm[0]);

    int m = stoi(dm[1]);

    int result = birthday(s, d, m);

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

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
