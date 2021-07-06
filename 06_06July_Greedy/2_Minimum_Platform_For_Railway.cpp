// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

//

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int cnt = 1,
        max_plat = 1,
        in = 1,
        ot = 0;

    while (in < n && ot < n)
    {
        if (arr[in] <= dep[ot])
        {
            cnt++;
            in++;
        }
        else
        {
            cnt--;
            ot++;
        }
        max_plat = max(max_plat, cnt);
    }
    return max_plat;
}