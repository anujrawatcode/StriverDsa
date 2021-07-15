#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &ans, vector<bool> &visit, vector<int> adj[], int src, int V)
    {
        queue<int> q;
        q.push(src);
        visit[src] = true;
        while (!q.empty())
        {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();

            for (auto v : adj[curr])
            {
                if (visit[v] == false)
                {
                    visit[v] = true;
                    q.push(v);
                }
            }
        }
    }

public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<bool> visit(V, false);
        for (int i = 0; i < V; i++)
        {
            if (visit[i] == false)
            {
                solve(ans, visit, adj, i, V);
            }
        }

        return ans;
    }
}; 