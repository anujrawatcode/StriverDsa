#include <bits/stdc++.h>
using namespace std;

int count(int arr[], int n, int sum)
{
    if (sum == 0 && n == 0)
        return 1;
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (sum > arr[n - 1])
        return count(arr, n - 1, sum);
    else
        return count(arr, n - 1, sum) + count(arr, n, sum - arr[n - 1]);
}
int main()
{
    int arr[] = {2, 5, 3, 6};
    int n = 4;
    int sum = 10;
    cout << count(arr, n, sum);
}