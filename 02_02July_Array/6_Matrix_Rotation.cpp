#include <bits/stdc++.h>
using namespace std;

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// transpose and reverse every row

// void rotate(vector<vector<int>>& m) {
        
//         int n=m.size();
        
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<n; j++) {
//                 if(i>=j)
//                     continue;
//                 swap(m[i][j], m[j][i]);
//             }
//         }
//         for(int i=0; i<n; i++) {
//             reverse(m[i].begin(), m[i].end());
//         }
//     }

void swapItem(vector<int> &temp)
{
    for (int i = 0; i < temp.size() / 2; i++)
    {
        int x = temp[i];
        temp[i] = temp[temp.size() - i - 1];
        temp[temp.size() - i - 1] = x;
    }
}

void rotate(vector<vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (i == j)
                continue;
            if (i > j)
                continue;
            else
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        swapItem(matrix[i]);
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
}
