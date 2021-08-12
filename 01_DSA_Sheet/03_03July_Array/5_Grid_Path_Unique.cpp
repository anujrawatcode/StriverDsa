#include <bits/stdc++.h>
using namespace std;

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

// TLE in DP also
class Solution_Brute
{
public:
    int solve(int r, int c, int i, int j)
    {
        if (i == r - 1 && j == c - 1)
            return 1;
        else if (i >= r || j >= c)
            return 0;
        else
            return (solve(r, c, i + 1, j) + solve(r, c, i, j + 1));
    }

public:
    int uniquePaths(int m, int n)
    {
        return solve(m, n, 0, 0);
    }
};

// O(m-1) Time
//        r+c-2 C r-1 or  r+c-2 C c-1

int uniquePaths(int m, int n)
{
    int N = m + n - 2;
    int r = m - 1;
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = (res * (N - r + i)) / i; // brakets are important

    return (int)res;
}
