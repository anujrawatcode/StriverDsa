// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// https://drive.google.com/drive/folders/1YjlZ6f1-3Lct3u5CFjq5yX-wMOISaD49?usp=sharing

#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i].first = start[i];
        vec[i].second = end[i];
    }

    sort(vec.begin(), vec.end(), sortbysec);

    int ans = 1;
    auto cur = vec[0];
    for (int i = 1; i < n; i++)
    {
        if (vec[i].first > cur.second)
        {
            cur = vec[i];
            ans++;
        }
    }

    return ans;
}
