#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Adjacency list: u -> list of {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // Priority queue stores tuples of {current_weight, node, consecutive_count}
        // We want a min-heap, so we use greater or handle it via negative weights.
        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> pq;
        
        // dist[u][count] stores the minimum weight to reach node u with a specific consecutive count.
        // Since count is 1-indexed up to k, we size the second dimension to k + 1.
        vector<vector<long long>> dist(n, vector<long long>(k + 1, -1));
        
        // Base case: Starting at node 0 with count 1 and weight 0.
        // Wait, for the starting node 0, its label is labels[0] and its count is 1.
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        
        while (!pq.empty()) {
            auto [w, u, count] = pq.top();
            pq.pop();
            
            // If we reached the destination node, return the distance
            if (u == n - 1) {
                return w;
            }
            
            if (w > dist[u][count]) continue;
            
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                int next_count;
                if (labels[u] == labels[v]) {
                    next_count = count + 1;
                } else {
                    next_count = 1;
                }
                
                // If the next count exceeds k, this path is invalid
                if (next_count > k) continue;
                
                long long next_w = w + weight;
                if (dist[v][next_count] == -1 || next_w < dist[v][next_count]) {
                    dist[v][next_count] = next_w;
                    pq.push({next_w, v, next_count});
                }
            }
        }
        
        return -1;
    }
};