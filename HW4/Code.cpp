#include <bits/stdc++.h>
using namespace std;

void topologicalSort(vector<vector<int>> &adj, vector<int> &sorted, vector<bool> &visited, int node, int t)
{
    visited[node] = true;
    if (node == t)
    {
        sorted.push_back(t);
        return;
    }
    for (auto neighbour : adj[node])
    {
        if (not visited[neighbour])
        {
            topologicalSort(adj, sorted, visited, neighbour, t);
        }
    }
    sorted.push_back(node);
}

vector<int> findCutVertices(vector<vector<int>> &adj, int n, int m, int src, int t)
{
    vector<int> sorted;
    vector<bool> visited(n + 1, false);
    topologicalSort(adj, sorted, visited, src, t);
    reverse(sorted.begin(), sorted.end());
    map<int, int> index;
    for (int i = 0; i <= sorted.size(); i++)
    {
        index[sorted[i]] = i;
    }
    int maxDist = 0;
    vector<int> cutVertex;
    for (int i = 1; i < sorted.size(); i++)
    {
        if (i > index[t]){
            break;
        }
        for (auto j : adj[sorted[i - 1]])
        {
            if (index[j] > maxDist and index[j] < index[t])
            {
                maxDist = index[j];
            }
        }
        if (maxDist <= i and maxDist != 0 and sorted[i] != src and sorted[i] != t)
        {
            cutVertex.push_back(sorted[i]);
        }
    }
    return cutVertex;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int sr, des;
    cin >> sr >> des;
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> result = findCutVertices(adj, n, m, sr, des);
    cout << "Cut Vertices: ";
    for (int v : result)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
