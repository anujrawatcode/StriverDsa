class Solution
{
public:
    bool isSafe(int r, int c, int n, vector<string> &board)
    {
        for (int i = 0; i < n; i++)
            if (board[i][c] == 'Q')
                return false;

        for (int i = 0; i < n; i++)
            if (board[r][i] == 'Q')
                return false;

        int dr = r;
        int dc = c;
        while (r >= 0 && c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        r = dr;
        c = dc;
        while (r >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }

        return true;
    }

public:
    void solve(int row, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        else
        {
            for (int col = 0; col < n; col++)
            {
                if (isSafe(row, col, n, board))
                {
                    board[row][col] = 'Q';
                    solve(row + 1, board, ans, n);
                    board[row][col] = '.';
                }
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }
};