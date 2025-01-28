// Problem-2658: Maximum Number of Fish in a Grid

// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// - A land cell if grid[r][c] = 0, or
// - A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:
// - Catch all the fish at cell (r, c), or
// - Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.
// Example 1:
// Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// Output: 7
// Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int Max = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    int C = 0;
                    queue<pair<int, int>> T;
                    T.push({i, j});
                    while (!T.empty()) {
                        auto [x, y] = T.front();
                        T.pop();
                        if (grid[x][y] > 0) {
                            C += grid[x][y];
                            grid[x][y] = 0; // Mark as visited
                            if (x > 0 && grid[x - 1][y] > 0) T.push({x - 1, y});
                            if (x + 1 < grid.size() && grid[x + 1][y] > 0) T.push({x + 1, y});
                            if (y > 0 && grid[x][y - 1] > 0) T.push({x, y - 1});
                            if (y + 1 < grid[0].size() && grid[x][y + 1] > 0) T.push({x, y + 1});
                        }
                    }
                    Max = max(Max, C);
                }
            }
        }
        return Max;
    }
};