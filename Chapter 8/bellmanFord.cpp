//bellmanFord algorithm
#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int V, int E, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);  // Set initial distances to "infinity"
    dist[src] = 0;  // Distance to the source is 0

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle\n";
            return;
        }
    }

    // Print the shortest distances
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; i++) {  // Corrected to iterate from 0 to V-1
        if (dist[i] == INT_MAX)
            cout << i << " INF\n";  // Changed "inf" to "INF"
        else
            cout << i << " " << dist[i] << "\n";
    }
}

int main() {
    int V, E, src;
    
    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E);

    // Input each edge with its source, destination, and weight
    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[i] = {u, v, weight};
    }

    // Input the source vertex
    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(V, E, edges, src);

    return 0;
}
