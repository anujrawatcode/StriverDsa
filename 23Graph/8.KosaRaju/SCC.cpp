#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
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

////////////////////  topo
void DFS_topo(vector<int> adj[], stack<int> &stk, int src, vector<bool> &visit)
{
    visit[src] = true;
    for (auto v : adj[src])
        if (!visit[v])
            DFS_topo(adj, stk, v, visit);
    stk.push(src);
}
void topo(int V, vector<int> adj[], stack<int> &stk)
{
    vector<bool> visit(V, false);
    for (int i = 0; i < V; i++)
        if (!visit[i])
            DFS_topo(adj, stk, i, visit);
}
// transpose
void transpose(int V, vector<int> adj[], vector<int> adjT[])
{
    for (int i = 0; i < V; i++)
        for (auto v : adj[i])    
            adjT[v].push_back(i);
}
// dfs by finishing time
void DFS(int V, vector<int> adj_trans[], vector<bool> &visit, int src)
{
    visit[src] = true;
    for (auto v : adj_trans[src])
        if (!visit[v])
            DFS(V, adj_trans, visit, v);
}
int dfs_stk(int V, stack<int> &stk, vector<int> adj_trans[])
{
    int cnt = 0;
    vector<bool> visit(V, false);
    while (!stk.empty())
    {
        int src = stk.top();
        if (!visit[src])
        {
            DFS(V, adj_trans, visit, src);
            cnt++;
        }
        stk.pop();
    }
    return cnt;
}
int kosaRaju(vector<int> adj[], int V)
{
    stack<int> stk;
    topo(V, adj, stk); //correct

    vector<int> adjT[V]; //correct
    transpose(V, adj, adjT);
    int ans = dfs_stk(V, stk, adjT);
    return ans;
    //printGraph(adjT, V);
    //return 0;
}

int main()
{
    int V = 6;
    vector<int> graph[V];

    addEdge(graph, 0, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 1, 0);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 3);
    addEdge(graph, 3, 5);
    addEdge(graph, 5, 4);

    cout << kosaRaju(graph, V);

    // printGraph(graph, V);
}
