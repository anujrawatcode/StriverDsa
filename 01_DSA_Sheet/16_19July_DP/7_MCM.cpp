#include <bits/stdc++.h>
using namespace std;


// https://drive.google.com/drive/folders/16Dt8uxTTr-zZ06hBTJ773x58HYUkZ5AO?usp=sharing

// https://www.youtube.com/watch?v=pEYwLmGJcvs&t=802s

int mcm(int arr[], int i, int j)
{
    if (i == j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {

        int count = mcm(arr, i, k) +
                    mcm(arr, k + 1, j) +
                    (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, count);
    }
    return ans;
}

class Solution
{
    int dp[101][101];

public:
    int MatrixChainOrder(int p[], int i, int j)
    {
        if (i == j)
            return 0;
        if (dp[i][j] == -1)
        {
            int ans = INT_MAX;
            int count;

            for (int k = i; k < j; k++)
            {
                count = MatrixChainOrder(p, i, k) +
                        MatrixChainOrder(p, k + 1, j) +
                        p[i - 1] * p[k] * p[j];
                ans = min(ans, count);
            }

            dp[i][j] = ans;
        }
        return dp[i][j];
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        int ans = MatrixChainOrder(arr, 1, N - 1);
        return ans;
    }
};

int main()
{
    memset(dp, -1, sizeof(dp));

    int a[] = {4, 3, 2, 5};
    int n = 4;
    cout << mcm_dp(a, 1, n - 1);
}