// https://leetcode.com/problems/merge-intervals


vector<vector<int>> merge(vector<vector<int>> &itrvel)
{
    int n = itrvel.size();
    if (n == 1)
        return itrvel;

    vector<vector<int>> ans;
    vector<int> temp(2);
    sort(itrvel.begin(), itrvel.end(), cmp);

    temp[0] = itrvel[0][0];
    temp[1] = itrvel[0][1];

    for (int i = 0; i < n; i++)
    {
        if (temp[1] >= itrvel[i][0])
        {
            // temp[1]=max(itrvel[i][1], temp[1]);
            temp[1] = itrvel[i][1];
        }

        else
        {
            ans.push_back(temp);
            temp[0] = itrvel[i][0];
            temp[1] = itrvel[i][1];
        }
    }
    ans.push_back(temp);
    return ans;
