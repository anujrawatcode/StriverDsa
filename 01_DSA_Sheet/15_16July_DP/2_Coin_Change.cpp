#include <bits/stdc++.h>
using namespace std;

int count(int arr[], int n, int sum)
{
    if (sum == 0 && n == 0)
        return 1;
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (sum > arr[n - 1])
        return count(arr, n - 1, sum);
    else
        return count(arr, n - 1, sum) + count(arr, n, sum - arr[n - 1]);
}

class Solution_DP
{
public:
    int coinChange(vector<int> &coins, int amt)
    {
        int n = coins.size();
        int dp[n + 1][amt + 1];

        for (int i = 0; i <= amt; i++)
            dp[0][i] = 1e5;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amt; j++)
            {
                if (coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i - 1][j],
                                   1 + dp[i][j - coins[i - 1]]);
            }
        }

        if (dp[n][amt] > 1e4)
            return -1;
        return dp[n][amt];
    }
};

int change_2(int amt, vector<int> &coins)
{
    int n = coins.size();
    int dp[n + 1][amt + 1];

    for (int i = 0; i <= amt; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amt; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] +
                           dp[i][j - coins[i - 1]];
        }
    }
    return dp[n][amt];
}

int main()
{
    int arr[] = {2, 5, 3, 6};
    int n = 4;
    int sum = 10;
    memset(dp, -1, sizeof(dp));
    cout << count(arr, n, sum);
}