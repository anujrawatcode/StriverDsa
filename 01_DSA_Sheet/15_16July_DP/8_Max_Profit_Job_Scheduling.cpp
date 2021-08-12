// Very long but simple to understand

{

    {
        bool compare(vector<int> v1, vector<int> v2)
        {
            if (v1[1] < v2[1])
            {
                return true;
            }
            return false;
        }

        class Solution
        {

        public:
            int solve(vector<int> &start, vector<int> &end, vector<int> &profit, int i, int LJobStr, int LJobEnd)
            {
                if (start.size() == i)
                    return 0;
                int currJstr = start[i];
                int currJend = end[i];
                int currJpft = profit[i];

                if (currJstr < LJobEnd)
                    return solve(start, end, profit, i + 1, LJobStr, LJobEnd);

                else
                    return max(solve(start, end, profit, i + 1, LJobStr, LJobEnd),
                               currJpft + solve(start, end, profit, i + 1, currJstr, currJend));
            }

        public:
            void arrange(vector<int> &start, vector<int> &end, vector<int> &profit)
            {

                int n = profit.size();

                cout << n << endl;

                vector<vector<int>> v;

                for (int i = 0; i < n; i++)
                {
                    v.push_back({start[i], end[i], profit[i]});
                }

                sort(v.begin(), v.end(), compare);

                for (int i = 0; i < n; i++)
                    start[i] = v[i][0];
                for (int i = 0; i < n; i++)
                    end[i] = v[i][1];
                for (int i = 0; i < n; i++)
                    profit[i] = v[i][2];
            }

        public:
            int jobScheduling(vector<int> &start, vector<int> &end, vector<int> &profit)
            {

                arrange(start, end, profit); //sort according to end time

                int i = 0;
                int LJobStr = -1;
                int LJobEnd = -1;
                return solve(start, end, profit, i, LJobStr, LJobEnd);
            }
        };
    }
}


