#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int rod(int price[], int length[], int n, int sum)
{
    if (sum == 0 || n == 0)
        return 0;
    if (length[n - 1] > sum)
        return rod(price, length, n - 1, sum);
    else
        return max(rod(price, length, n - 1, sum),
                   price[n - 1] + rod(price, length, n, sum - length[n - 1]));
}

int rod_dp(int price[], int length[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < sum + 1; i++)
        dp[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (length[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j],
                               price[i - 1] + dp[i][j - length[i - 1]]);
        }
    }
    return dp[n][sum];
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;
    int sum = 8;
    cout << rod_dp(price, length, n, sum);
}