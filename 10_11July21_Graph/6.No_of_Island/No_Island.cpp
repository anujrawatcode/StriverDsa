#include <bits/stdc++.h>
using namespace std;

// Idea is to do dfs and shrink the island if covered
void dfs(vector<vector<char>> &grid, int n, int m, int i, int j)
{
    if (i < 0 || j < 0 || i > n - 1 || j > m - 1 || grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    dfs(grid, n, m, i - 1, j);
    dfs(grid, n, m, i, j - 1);
    dfs(grid, n, m, i + 1, j);
    dfs(grid, n, m, i, j + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '1')
            {
                cnt++;
                dfs(grid, n, m, i, j);
            }
    return cnt;
}
