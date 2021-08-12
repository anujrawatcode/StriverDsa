#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)
{
    // Same as LIS just maintain sum array rather then length array
    int sum[n];
    for (int i = 0; i < n; i++)
        sum[i] = arr[i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                if (sum[j] + arr[i] > sum[i])
                    sum[i] = sum[j] + arr[i];

    int max = sum[0];
    for (int i = 0; i < n; i++)
        if (sum[i] > max)
            max = sum[i];
    return max;
}