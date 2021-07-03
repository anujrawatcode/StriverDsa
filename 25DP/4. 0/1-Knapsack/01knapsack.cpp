#include <bits/stdc++.h>
using namespace std;

int knapSack_Rec(int W, int wt[], int val[], int n)
{
    if (W == 0 || n == 0) // capacity is 0 or No item in store so no profit
        return 0;
    else if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapSack_Rec(W - wt[n - 1], wt, val, n - 1),
                   knapSack_Rec(W, wt, val, n - 1)); // max of when included and not-included
    }
    else
    {
        return knapSack_Rec(W, wt, val, n - 1);
    }
}

int knapSack(int wt[], int val[], int n, int k)
{
    int i, w;
    int K[n + 1][k + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= k; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            cout << K[i][j] << " ";
        }
        cout << endl;
    }

    return K[n][k];
}

int main()
{
    int val[] = {5, 6, 4, 5, 9};
    int wt[] = {2, 5, 4, 1, 3};
    int W = 6;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(wt, val, n, W);
    return 0;
}