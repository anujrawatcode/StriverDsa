#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

bool allUnique(string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
        mp[s[i]]++;
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->second > 1)
            return false;
    return true;
}
void solve(string s)
{
    int n = s.length();
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
        {
            string temp = s.substr(i, len);
            if (allUnique(temp))
            {
                int x = temp.length();
                maxi = max(maxi, x);
            }
        }
    }
    cout << maxi;
}
int main()
{
    string s;
    cin >> s;
    solve(s);
}