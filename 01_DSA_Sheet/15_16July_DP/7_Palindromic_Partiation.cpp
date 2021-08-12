class Solution_Recursive
{

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        Solve(s, ans, temp, 0);
        return ans;
    }

public:
    void Solve(string s, vector<vector<string>> &ans, vector<string> &temp, int idx)
    {
        if (idx == s.length())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++)
        {
            if (isPal(s, idx, i))
            {
                temp.push_back(s.substr(idx, i - idx + 1));
                Solve(s, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }

public:
    bool isPal(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

