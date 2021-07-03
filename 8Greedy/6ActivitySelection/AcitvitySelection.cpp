#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &a,
          const pair<int, int> &b)
{
    return (a.second < b.second);
}

int solve(int start[], int finish[], int n)
{
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i].first = start[i];
        vec[i].second = finish[i];
    }
    sort(vec.begin(), vec.end(), comp);

    int activity = 1;
    auto current = vec[0];

    for (int i = 1; i < n; i++)
    {
        if (current.second <= vec[i].first)
        {
            current = vec[i];
            activity++;
        }
    }
    return activity;
}


int main()
{
    int start[] = {1, 3, 0, 5, 5, 8};
    int finish[] = {2, 4, 6, 7, 9, 9};
    cout << solve(start, finish, 6);
}