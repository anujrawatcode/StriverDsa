class Solution_Recursive
{
public:
    int solve(vector<vector<int>> &grid, int r, int c, int i, int j)
    {
        if (r - 1 < i || c - 1 < j)
            return 100000;
        if (i == r - 1 && j == c - 1)
            return grid[i][j];
        return min(grid[i][j] + solve(grid, r, c, i + 1, j),
                   grid[i][j] + solve(grid, r, c, i, j + 1));
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return solve(grid, m, n, 0, 0);
    }
};

class Solution_DP
{
public:
    int dp[201][201];

public:
    int solve(vector<vector<int>> &grid, int r, int c, int i, int j)
    {
        if (r - 1 < i || c - 1 < j)
            return 100000;
        if (i == r - 1 && j == c - 1)
            return grid[i][j];
        if (dp[i][j] == -1)
            dp[i][j] = min(grid[i][j] + solve(grid, r, c, i + 1, j),
                           grid[i][j] + solve(grid, r, c, i, j + 1));
        return dp[i][j];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, m, n, 0, 0);
    }
};