class Solution
{

public:
    int superEggDrop(int e, int f)
    {
        int dp[e + 1][f + 1];
        memset(dp, -1, sizeof(dp));

        for (int i = 1; i <= e; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for (int i = 0; i <= f; i++)
            dp[1][i] = i;

        for (int i = 2; i <= e; i++)
        {
            for (int j = 2; j <= f; j++)
            {

                int ans = INT_MAX;
                for (int mj = j - 1, pj = 0; mj >= 0; mj--, pj++)
                {
                    int v1 = dp[i][mj];
                    int v2 = dp[i - 1][pj];
                    int val = max(v1, v2);
                    ans = min(ans, val);
                }
                dp[i][j] = ans + 1;
            }
        }

        return dp[e][f];
    }
};

int eggDrop(int n, int k)
{
    
    if (k == 1 || k == 0)
        return k;

    if (n == 1)
        return k;

    int min = INT_MAX, x, res;

    for (x = 1; x <= k; x++)
    {
        res = max(
            eggDrop(n - 1, x - 1),
            eggDrop(n, k - x));
        if (res < min)
            min = res;
    }

    return min + 1;
}