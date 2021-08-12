string longestPalindrome(string s)
{

    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int maxLength = 1;
    int start = 0;

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; k++) // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i)
        {

            int j = i + k - 1;

            if (dp[i + 1][j - 1] && s[i] == s[j])
            {
                dp[i][j] = true;

                start = i;
                maxLength = max(maxLength, k);
            }
        }

    return s.substr(start, maxLength);
}