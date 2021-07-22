// Reverse words in a given string

// Input: s = “geeks quiz practice code”
// Output: s = “code practice quiz geeks”

// Input: s = “getting good at coding needs a lot of practice”
// Output: s = “practice of lot a needs coding at good getting”

#include <bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void solve(string &s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);

    auto i = s.begin();
    for (auto j = s.begin(); j != s.end() + 1; j++)
    {
        if (*j == ' ' || j == s.end())
        {
            reverse(i, j);
            i = j + 1;
            j++;
        }
    }
    cout << s;
}

int main()
{
    string s;
    // getline(cin, s);
    s = "geeks quiz practice";
    solve(s);
    // cout << s;
}