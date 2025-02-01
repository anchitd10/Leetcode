// Problem-827: Making A Large Island

// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation.
// An island is a 4-directionally connected group of 1s.
// Example 1:
// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:
// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, int islandId) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) {
            return 0;
        }

        grid[x][y] = islandId; // Mark the cell with the island ID
        int size = 1;

        // Directions for moving up, right, down, and left
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (const auto& dir : directions) {
            size += dfs(grid, x + dir[0], y + dir[1], islandId);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int islandId = 2; // Start island IDs from 2 (since 0 and 1 are already used)
        unordered_map<int, int> islandSizes; // Maps island ID to its size

        // Directions for moving up, right, down, and left
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // Step 1: Assign unique IDs to each island and calculate their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    islandSizes[islandId] = size;
                    islandId++;
                }
            }
        }

        // Step 2: Evaluate each 0 to see if changing it to 1 can connect islands
        int maxIslandSize = islandSizes.empty() ? 0 : max_element(islandSizes.begin(), islandSizes.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> connectedIslands;
                    int potentialSize = 1; // Start with the current cell being changed to 1

                    // Check all four directions
                    for (const auto& dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            connectedIslands.insert(grid[ni][nj]);
                        }
                    }

                    // Sum the sizes of connected islands
                    for (const auto& id : connectedIslands) {
                        potentialSize += islandSizes[id];
                    }

                    maxIslandSize = max(maxIslandSize, potentialSize);
                }
            }
        }

        return maxIslandSize;
    }
};