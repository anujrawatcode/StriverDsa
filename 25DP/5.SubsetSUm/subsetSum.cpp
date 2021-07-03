#include <bits/stdc++.h>
using namespace std;

bool subSet_Rc(int set[], int n, int sum)
{
    if (sum == 0 && n == 0)
        return true;
    else if (sum == 0)
        return true;
    else if (n == 0)
        return false;
    else if (set[n - 1] > sum)
        return subSet_Rc(set, n - 1, sum);
    else
        return (subSet_Rc(set, n - 1, sum) || subSet_Rc(set, n - 1, sum - set[n - 1]));
}

bool subSet_dp(int set[], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            else
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}
int main()
{
    int set[] = {1, 3, 2, 4};
    int sum = 7;
    int n = 4;
    cout << subSet_dp(set, n, sum);
}