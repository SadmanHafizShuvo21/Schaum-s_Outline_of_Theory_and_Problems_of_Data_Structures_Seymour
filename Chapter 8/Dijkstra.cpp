// Dijkstra's Algorithm
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5;

int main() {
    int vertices, edges;  
    cout << "Enter the number of vertices and edges:\n";
    cin >> vertices >> edges; // Number of vertices and edges

    // Initialize distances to "infinity"
    vector<int> dist(vertices + 1, inf);
    vector<vector<pair<int, int>>> graph(vertices + 1);

    cout << "Enter each edge in the format (u v w):\n";
    // Input graph edges
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For undirected graph; remove this line for directed graph
    }

    cout << "Enter the source vertex:\n";
    int src;  // Source vertex
    cin >> src;
    dist[src] = 0;

    // Set to store pairs of (distance, vertex)
    set<pair<int, int>> store;
    store.insert({0, src});

    // Dijkstra's Algorithm
    while (!store.empty()) {
        auto x = *(store.begin());
        store.erase(x);

        int u = x.second; // current vertex
        int d = x.first;  // current distance

        for (auto it : graph[u]) {
            int v = it.first;
            int weight = it.second;

            // Check if a shorter path to v is found
            if (dist[v] > dist[u] + weight) {
                // If v is already in the set, erase it
                store.erase({dist[v], v});
                dist[v] = dist[u] + weight;
                store.insert({dist[v], v});
            }
        }
    }

    // Output shortest distances from source to all vertices
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 1; i <= vertices; i++) {
        if (dist[i] < inf)
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        else
            cout << "Vertex " << i << ": -1 (unreachable)\n"; // Vertex is unreachable
    }

    return 0;
}
