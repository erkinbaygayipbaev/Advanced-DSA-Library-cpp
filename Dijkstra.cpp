#include <iostream>
#include <vector>
#include <queue>
#include <climits>
/**
 * Dijkstra's Algorithm implementation for finding the shortest path 
 * in a weighted graph.
 * Time Complexity: O(E log V) using a Priority Queue.
 */
using namespace std;
// Representing a weighted edge: (target_node, weight)
typedef pair<int, int> pii;
class Graph {
private:
    int V; // Number of vertices
    vector<vector<pii>> adj; // Adjacency list
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    // Function to add a directed weighted edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        // For undirected graph, add: adj[v].push_back({u, w});
    }
    // Dijkstra's algorithm to find shortest paths from source 'src'
    void dijkstra(int src) {
        // Priority queue to store (distance, node), min-heap
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // Distances initialized to infinity
        vector<int> dist(V, INT_MAX);
        // Source node has distance 0
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            // Check all neighbors of u
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If a shorter path to v is found
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        // Print the shortest distances
        cout << "Shortest distances from source " << src << ":" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "To node " << i << " : " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
        }
    }
};
int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 2, 7);
    g.addEdge(4, 1, 1);
    g.addEdge(4, 2, 8);
    g.addEdge(4, 3, 2);
    g.dijkstra(0);
    return 0;
}
