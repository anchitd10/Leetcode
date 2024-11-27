// Problem-3243: Shortest Distance After Road Addition Queries I

// You are given an integer n and a 2D integer array queries.
// There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.
// queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.
// Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.Example 1:
// Example:
// Input: n = 5, queries = [[2,4],[0,2],[0,4]]
// Output: [3,2,1]

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph[i].emplace_back(i + 1, 1);
        }

        // Dijkstra's algorithm.
        auto dijkstra = [&]() -> int {
            vector<int> dist(n, INT_MAX);
            dist[0] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, 0); // (distance, node)

            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();

                if (d > dist[node]) continue;

                for (auto [neighbor, weight] : graph[node]) {
                    if (dist[node] + weight < dist[neighbor]) {
                        dist[neighbor] = dist[node] + weight;
                        pq.emplace(dist[neighbor], neighbor);
                    }
                }
            }

            return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
        };

        vector<int> result;

        // process each query and calculate the shortest path
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].emplace_back(v, 1);
            result.push_back(dijkstra());
        }

        return result;
    }
};