class Solution {
    public:
      bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
          // Initialize distances to 0 to handle disconnected components
          vector<int> dist(V, 0);

          // Relax all edges V - 1 times
          for (int i = 0; i < V - 1; i++) {
              for (const auto& edge : edges) {
                  int u = edge[0];
                  int v = edge[1];
                  int weight = edge[2];

                  if (dist[u] + weight < dist[v]) {
                      dist[v] = dist[u] + weight;
                  }
              }
          }

          // Check for negative-weight cycles on the V-th iteration
          for (const auto& edge : edges) {
              int u = edge[0];
              int v = edge[1];
              int weight = edge[2];

              if (dist[u] + weight < dist[v]) {
                  return true; // Negative cycle detected
              }
          }

          return false;
      }
  };