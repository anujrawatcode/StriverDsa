#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<int> adj[], int src, vector<bool> &visit, vector<int> &result)
    {
        visit[src] = true;
        result.push_back(src);
        for (auto v : adj[src])
            if (!visit[v])
                DFS(adj, v, visit, result);
    }

public:
    //Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visit(V, false);
        vector<int> result;
        for (int i = 0; i < V; i++) // Go to every component
            if (!visit[i])          // if not visited
                DFS(adj, i, visit, result);
        return result;
    }
};
    
class Solution
{
public:
    void DFS(vector<int> adj[], vector<int> result, vector<bool> visit, int src)
    {
        stack<int> stk;
        stk.push(src);
        visit[src] = true;

        while (!stk.empty())
        {
            int u = stk.top();
            stk.pop();
            result.push_back(u);

            for (auto v : adj[u])
                if (!visit[v])
                {
                    stk.push(v);
                }
        }
    }

public:
    //Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> result;
        vector<bool> visit(V, 0);
        for (int i = 0; i < V; i++)
            if (!visit[i])
                DFS(adj, result, visit, i);
        return result;
    }
};