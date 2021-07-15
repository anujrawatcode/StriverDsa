#include <bits/stdc++.h>
using namespace std;
bool cycleDFS(vector<int> graph[], vector<bool> &visited, int node, int parent);
void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void printGraph(vector<int> graph[], int V)
{

    for (int i = 0; i < V; i++)
    {
        cout << i << ":";
        for (int j : graph[i])
        {
            cout << "->" << j;
        }
        cout << endl;
    }
}

// Detecting cycle in undirected graph by DFS
bool component_cycle(vector<int> graph[], int V) // for various disconnected component of graph
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)                 // parent for starting : -1
            if (cycleDFS(graph, visited, i, -1)) //If a cycle in a component return true
                return true;
    return false;
}

bool cycleDFS(vector<int> graph[], vector<bool> &visited, int node, int parent)
{
    visited[node] = true;                          // Always mark visited node
    for (auto v : graph[node])
    {
        if (visited[v] == false)                  // if adj node is un-visited call dfs for it
        {
            return cycleDFS(graph, visited, v, node);
        }
        else if (v != parent)                       
            return true;
    }
    return false;                            //Note: If adj node is true and it is parent don't return true
}

int main()
{
    int V = 7;
    vector<int> graph[7];

    addEdge(graph, 0, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 6, 5);

    // printGraph(graph, V);

    cout << component_cycle(graph, V);
}