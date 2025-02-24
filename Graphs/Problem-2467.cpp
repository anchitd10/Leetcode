// Problem-2467: Most Profitable Path in a Tree

// There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

// - the price needed to open the gate at node i, if amount[i] is negative, or,
// - the cash reward obtained on opening the gate at node i, otherwise.
// The game goes on as follows:
// - Initially, Alice is at node 0 and Bob is at node bob.
// - At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
// - For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
// - If the gate is already open, no price will be required, nor will there be any cash reward.
// - If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
// - If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
// Return the maximum net income Alice can have if she travels towards the optimal leaf node.

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> bobPath(n, -1);
        vector<int> path;
        
        function<bool(int, int)> fillBobPath = [&](int node, int parent) {
            if (node == 0) return true;
            
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    path.push_back(node);
                    if (fillBobPath(neighbor, node)) return true;
                    path.pop_back();
                }
            }
            return false;
        };

        fillBobPath(bob, -1);
        for (int i = 0; i < path.size(); i++) {
            bobPath[path[i]] = i;
        }

        function<int(int, int, int, int)> getAliceMaxScore = [&](int node, int parent, int currScore, int timestamp) {
            if (bobPath[node] == -1 || bobPath[node] > timestamp) {
                currScore += amount[node];
            } else if (bobPath[node] == timestamp) {
                currScore += amount[node] / 2;
            }

            if (graph[node].size() == 1 && node != 0) return currScore;

            int maxScore = INT_MIN;
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    maxScore = max(maxScore, getAliceMaxScore(neighbor, node, currScore, timestamp + 1));
                }
            }
            return maxScore;
        };

        return getAliceMaxScore(0, -1, 0, 0);
    }
};