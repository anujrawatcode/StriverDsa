#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    if (matrix.size() == 0)
        return false;

    int n = matrix.size();
    int m = matrix[0].size();

    int l = 0;
    int h = (n * m) - 1;

    while (l <= h)
    {
        int mid = (l + (h - l) / 2);
        int r = mid / m;
        int c = mid % m;

        if (matrix[mid / m][mid % m] == target)
            return true;
        else if (matrix[mid / m][mid % m] < target)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return false;
}