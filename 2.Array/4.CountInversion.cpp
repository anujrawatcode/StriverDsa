#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int arr[] = {3, 2, 1};
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; i < n; j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    cout<<cnt;
}