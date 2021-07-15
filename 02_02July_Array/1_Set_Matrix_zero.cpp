
// https://leetcode.com/problems/set-matrix-zeroes/


#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    bool first_r = false;

    for (int i = 0; i < c; i++)
        if (matrix[0][i] == 0)
            first_r = true;

    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = r - 1; i >= 1; i--)
    {
        for (int j = c - 1; j >= 0; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (first_r)
        for (int i = 0; i < c; i++)
            matrix[0][i] = 0;
}