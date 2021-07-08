// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

// https://drive.google.com/drive/folders/1YjlZ6f1-3Lct3u5CFjq5yX-wMOISaD49?usp=sharing

bool comp(Job a, Job b)
{
    return (a.profit > b.profit);
}
class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
            if (arr[i].dead > maxi)
                maxi = arr[i].dead;

        vector<int> slot(n + 1, -1);

        int jobs = 0, profit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    jobs++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }

        vector<int> ans(2, -1);
        ans[0] = jobs, ans[1] = profit;
        return ans;
    }
};