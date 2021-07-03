#include <bits/stdc++.h>
using namespace std;

// int editDis_Rc(string s1, string s2, int n1, int n2)
// {
//     if (n1 == 0)
//         return n2;
//     if (n2 == 0)
//         return n1;
//     if (s1[n1 - 1] == s2[n2 - 1])
//         return editDis_Rc(s1, s2, n1 - 1, n2 - 1);
//     else
//         return 1 + min(editDis_Rc(s1, s2, n1 - 1, n2),
//                        editDis_Rc(s1, s2, n1, n2 - 1),
//                        editDis_Rc(s1, s2, n1 - 1, n2 - 1));
// }

int MINI(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int editDis_dp(string s1, string s2, int n1, int n2)
{
    int dp[n1 + 1][n2 + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n1 + 1; i++)
        dp[i][0] = i;
    for (int i = 0; i < n2 + 1; i++)
        dp[0][i] = i;

    for (int i = 1; i < n1 + 1; i++)
    {
        for (int j = 1; j < n2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + MINI(dp[i - 1][j],
                                    dp[i][j - 1],
                                    dp[i - 1][j - 1]);
        }
    }
    return dp[n1][n2];
}

int main()
{
    int n = editDis_dp("abc", "dc", 3, 3);
    //cout << "hi";
}