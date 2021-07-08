#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int r, int c, char k)
    {
        for (int i = 0; i < board.size(); i++)
            if (board[r][i] == k)
                return false;

        for (int i = 0; i < board.size(); i++)
            if (board[i][c] == k)
                return false;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[3 * (r / 3) + i][3 * (c / 3) + j] == k)
                    return false;
            }
        }

        return true;
    }

public:
    bool solve(vector<vector<char>> &board, int n)
    {
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (board[r][c] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isSafe(board, r, c, k))
                        {
                            board[r][c] = k;
                            if (solve(board, n))
                            {
                                return true;
                            }
                            else
                                board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        int n = board.size();
        bool ans = solve(board, n);
    }
};