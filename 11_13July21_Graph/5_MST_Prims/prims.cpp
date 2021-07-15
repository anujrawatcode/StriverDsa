#include <bits/stdc++.h>
using namespace std;
// https://drive.google.com/drive/folders/1GYR-eUoFCOf0RPepVaVGcjT9QKCP9nxp?usp=sharing
vector<int> spanningTree(int N, vector<vector<int>> adj[])
{
    // code here
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < N - 1; count++)
    {

        int mini = INT_MAX, u;

        for (int v = 0; v < N; v++)
            if (mstSet[v] == false && key[v] < mini)
                mini = key[v], u = v;

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it[0];
            int weight = it[1];
            if (mstSet[v] == false && weight < key[v])
                parent[v] = u, key[v] = weight;
        }
    }
    return parent;
}