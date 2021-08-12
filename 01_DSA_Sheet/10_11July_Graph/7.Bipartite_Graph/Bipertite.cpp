bool Solve(vector<vector<int>> &graph, int V, vector<int> &color, int src)
{
    if (color[src] == -1)
        color[src] = 1;

    for (auto it : graph[src])
    {
        if (color[it] == -1) 
        {
            color[it] = 1 - color[src];
            if (!Solve(graph, V, color, it))
            {
                return false;
            }
        }
        else if (color[it] == color[src])
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
        if (color[i] == -1)
            if (!Solve(graph, V, color, i))
                return false;
    return true;
}