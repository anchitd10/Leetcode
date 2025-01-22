// Problem-1765: Map of Highest Peak

// You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
// - If isWater[i][j] == 0, cell (i, j) is a land cell.
// - If isWater[i][j] == 1, cell (i, j) is a water cell.
// You must assign each cell a height in a way that follows these rules:
// - The height of each cell must be non-negative.
// - If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is maximized.
// Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
// Example 1:
// Input: isWater = [[0,1],[0,0]]
// Output: [[1,0],[2,1]]
// Explanation: The image shows the assigned heights of each cell.
// The blue cell is the water cell, and the green cells are the land cells.

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        // initialize water cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j]) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // BFS directions
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // BFS from water to land
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) {
                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return height;
    }
};