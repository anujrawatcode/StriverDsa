// https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/

// https://drive.google.com/drive/folders/1YjlZ6f1-3Lct3u5CFjq5yX-wMOISaD49?usp=sharing

#include <bits/stdc++.h>
using namespace;

int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V)
{
    sort(deno, deno + n);

    // Initialize result
    vector<int> ans;

    // Traverse through all denomination
    for (int i = n - 1; i >= 0; i--)
    {

        // Find denominations
        while (V >= deno[i])
        {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    // Print result
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}