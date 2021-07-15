#include <bits/stdc++.h>
using namespace std;

// https://drive.google.com/drive/folders/1GYR-eUoFCOf0RPepVaVGcjT9QKCP9nxp?usp=sharing

void addEdge(vector<pair<int, int>> graph[], int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int src)
{
    vector<int> dis(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, src));
    dis[src] = 0;

    while (!pq.empty())
    {
        auto u = pq.top();
        int dist = u.first;
        int prev = u.second;
        pq.pop();

        for (auto v : adj[prev])
        {
            int next = v.first;
            int nextDist = v.second;

            if (dis[prev] + nextDist < dis[next])
            {
                dis[next] = dis[prev] + nextDist;
                pq.push(make_pair(dis[next], next));
            }
        }
    }
    return dis;
}
int main()
{
    int V = 5;
    vector<pair<int, int>> graph[V];

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 3, 2, 3);
    addEdge(graph, 2, 4, 1);

    vector<int> ans = dijkstra(V, graph, 0);

    for (int i = 0; i < V; i++)
        cout << ans[i] << " ";
}