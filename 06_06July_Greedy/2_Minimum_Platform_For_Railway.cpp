// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

// https://drive.google.com/drive/folders/1YjlZ6f1-3Lct3u5CFjq5yX-wMOISaD49?usp=sharing

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