#include <bits/stdc++.h>
using namespace std;
bool isCycle(int V, vector<int> adj[]);

// Detect cycle in Undirected graph by dfs
bool isCycle(int V, vector<int> adj[]) // To cover all the disconnected component
{
    vector<int> vis(V, 0);        // visited[] to track visited node
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (checkForCycle(i, -1, vis, adj))
                return true;
    }
    return false;
}

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;             // mark node as visited
    for (auto it : adj[node])  // check all adjacent of node
    {
        if (!vis[it])         //adj not visited dfs for it
        {
            if (checkForCycle(it, node, vis, adj))
                return true;
        }
        else if (it != parent) // adj = visited and its not a parent
            return true;
    }
    return false;             // No cycle
}



void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}
void printGraph(vector<int> graph[], int V)
{

    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int j : graph[i])
        {
            cout << "->" << j;
        }
        cout << endl;
    }
}


int main()
{
    int V = 3;
    vector<int> graph[V];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);

    cout << isCycle(V, graph);

    printGraph(graph, V);
}