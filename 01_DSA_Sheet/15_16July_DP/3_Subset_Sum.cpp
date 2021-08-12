#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int N, int arr[], int sum)
{
    if (sum == 0 && N == 0)
        return true;
    if (sum == 0)
        return true;
    if (N == 0)
        return false;
    if (sum < arr[N - 1])
        return isSubsetSum(N - 1, arr, sum);
    else
        return isSubsetSum(N - 1, arr, sum) ||
               isSubsetSum(N - 1, arr, sum - arr[N - 1]);
}

bool isSubsetSum_DP(int N, int arr[], int sum)
{
    bool dp[N + 1][sum + 1];

    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 0; i <= N; i++)
        dp[i][0] = true;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] ||
                           dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[N][sum];
}