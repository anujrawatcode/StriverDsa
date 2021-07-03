#include<bits/stdc++.h>
using namespace std;


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

    printGraph(graph, V);

}