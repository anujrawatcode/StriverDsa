#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int LCS_Re(string s1, int n1, string s2, int n2)
{
    if (n1 == 0 || n2 == 0)
        return 0;
    else if (s1[n1 - 1] == s2[n2 - 1])
        return LCS_Re(s1, n1 - 1, s2, n2 - 1);
    else
        return max(LCS_Re(s1, n1 - 1, s2, n2),
                   LCS_Re(s1, n1, s2, n2 - 1));
}

int LCS_dp(string s1, int n1, string s2, int n2)
{
    int dp[n1 + 1][n2 + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n1 + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < n2 + 1; i++)
        dp[0][i] = 0;

    for (int i = 1; i < n1 + 1; i++)
    {
        for (int j = 1; j < n2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }
    }

    return dp[n1][n2];
}

int main()
{
    int n1 = 4, n2 = 6;
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";
    cout << LCS_dp(str1, n1, str2, n2);
}