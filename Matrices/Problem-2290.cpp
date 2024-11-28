// Problem-2290: Minimum Obstacle Removal to Reach Corner

// You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
// 0 represents an empty cell,
// 1 represents an obstacle that may be removed.
// You can move up, down, left, or right from and to an empty cell.
// Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).
// Example:
// Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
// Output: 2
// Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
// It can be shown that we need to remove at least 2 obstacles, so we return 2.
// Note that there may be other ways to remove 2 obstacles to create a path.

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // minimum number of obstacles removed to reach each cell
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        deque<pair<int, int>> dq;
        dq.push_front({0, 0}); // start from the top-left corner

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Check bounds
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = dist[x][y] + grid[nx][ny];
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny}); // No obstacle
                        } else {
                            dq.push_back({nx, ny}); // Obstacle
                        }
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};