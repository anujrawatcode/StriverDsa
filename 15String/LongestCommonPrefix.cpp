#include <bits/stdc++.h>
using namespace std;

string commonPrefix(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    string result;

    for (int i = 0, j = 0; i < n1 && j < n2; i++, j++)
    {
        
    }
}

string commonPrefix(vector<string> &vec, int n)
{
    string prefix = vec[0];
    for (int i = 1; i < n; i++)
        prefix = commonPrefix(prefix, vec[i]);
    return prefix;
}

int main()
{
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    string ans = commonPrefix(vec, n);

    if (ans.length())
        cout << ans;
    else
        cout << "No";
}