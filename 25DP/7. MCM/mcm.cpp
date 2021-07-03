#include <bits/stdc++.h>
using namespace std;

// int mcm(int arr[], int i, int j)
// {
//     if (i >= j)
//         return 0;
//     int ans = INT_MAX;
//     for (int k = i; k <= j - 1; k++)
//     {

//         int ansf = mcm(arr, i, k) +
//                    mcm(arr, k + 1, j) +
//                    (arr[i - 1] * arr[k] * arr[j]);
//         ans = min(ans, ansf);
//     }
//     return ans;
// }

int static dp[1001][1001];
int mcm_dp(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {

        int ansf = mcm_dp(arr, i, k) +
                   mcm_dp(arr, k + 1, j) +
                   (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, ansf);
    }
    return dp[i][j] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));

    int a[] = {4, 3, 2, 5};
    int n = 4;
    cout << mcm_dp(a, 1, n - 1);
}