#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    int lastPage = 1;
    std::vector<std::pair<int, int>> pages;
    for (int i = 0; lastPage < n; i++) 
    {
        if (i == 0) 
        {
            pages.emplace_back(pair<int, int>(0, 1));
        }else
        {
            pages.emplace_back(pair<int, int>(i * 2, i * 2 + 1));
            lastPage = i * 2 + 1;
        }
    }
    if (p <= n / 2) 
    {
        for (int i = 0; i < pages.size(); i++) 
        {
            if (p == pages[i].first || p == pages[i].second) 
            {
                return i;
            }
        }
    }
    else 
    {
        int counter = 0;
        for (int i = pages.size() - 1; i > 0; i--,counter++)
        {
            if (p == pages[i].first || p == pages[i].second)
            {
                return counter;
            }
        }
    }
    return 0;
}

int main()
{
    ofstream fout("c:\\source\\test1.txt");

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
