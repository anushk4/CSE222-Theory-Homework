#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int from, to, capacity, flow;
};

int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<Edge> edges;
    
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            edges.push_back({u, v, 1, 0});
        }
    }

    vector<vector<int>> residual(n, vector<int>(n, 0));
    for (auto& e : edges) {
        residual[e.from][e.to] = e.capacity;
    }

    vector<int> parent(n);

    int maxFlow = 0;
    while (true) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        queue<pair<int, int>> q;
        q.push({source, INF});

        while (!q.empty()) {
            int u = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int v : graph[u]) {
                if (parent[v] == -1 && residual[u][v] > 0) {
                    parent[v] = u;
                    int new_flow = min(flow, residual[u][v]);
                    if (v == sink) {
                        maxFlow += new_flow;
                        while (v != source) {
                            int u = parent[v];
                            residual[u][v] -= new_flow;
                            residual[v][u] += new_flow;
                            v = u;
                        }
                        goto found_path;
                    }
                    q.push({v, new_flow});
                }
            }
        }
        break;
        
        found_path:;
    }

    return maxFlow;
}

vector<vector<int>> buildFlowNetwork(const vector<vector<int>>& boxes) {
    int n = boxes.size();
    int source = 0;
    int sink = n * 2 + 1;
    vector<vector<int>> graph(n * 2 + 2);

    for (int i = 1; i <= n; ++i) {
        graph[source].push_back(i);
    }

    for (int i = n + 1; i <= n * 2; ++i) {
        graph[i].push_back(sink);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool can_nest = true;
            for (int k = 0; k < 3; ++k) {
                if (boxes[j][k] >= boxes[i][k]) {
                    can_nest = false;
                    break;
                }
            }
            if (can_nest) {
                graph[i + 1].push_back(j + n + 1);
            }
        }
    }

    return graph;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> boxes(n,vector<int>());
    for (int i = 0; i < n; i++)
    {
        int l,b,h;
        cin >> l >> b >> h;
        boxes[i].push_back(l);
        boxes[i].push_back(b);
        boxes[i].push_back(h);
    }
    vector<vector<int>> graph = buildFlowNetwork(boxes);
    int source = 0;
    int sink = n * 2 + 1;

    int maxFlow = fordFulkerson(graph, source, sink);

    int min_visible_boxes = n - maxFlow;

    cout << "Minimum number of visible boxes: " << min_visible_boxes << endl;
    return 0;
}