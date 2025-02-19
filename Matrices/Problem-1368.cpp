// Problem-1368: Minimum Cost to Make at Least One Valid Path in a Grid

// Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
// - 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
// - 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
// - 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
// - 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
// Notice that there could be some signs on the cells of the grid that point outside the grid.
// You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.
// You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
// Return the minimum cost to make the grid have at least one valid path.
// Example 1:
// Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
// Output: 3
// Explanation: You will start at point (0, 0).
// The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
// The total cost = 3.

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        
        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            int curDir = grid[x][y] - 1;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                int cost = dist[x][y] + (dir == curDir ? 0 : 1);
                if (cost < dist[nx][ny]) {
                    dist[nx][ny] = cost;
                    if (dir == curDir) dq.push_front({nx, ny});
                    else dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};