#include<bits/stdc++.h>
using namespace std;


int lengthOfLIS(vector<int> &arr, int n)
{

    vector<int> lis(n, 1); // store the length of LISs

    for (int i = 1; i < n; i++)   // front pointer
    { 
        for (int j = 0; j < i; j++) // back pointer
        {
            //  no is increasing    
            if (arr[i] > arr[j] && lis[i] <= lis[j])
                lis[i] = lis[j] + 1;
        }
    }

    int ans = 0;
    for (auto it : lis)
        if (it > ans)
            ans = it;
    return ans;
}


int main()
{
    
}