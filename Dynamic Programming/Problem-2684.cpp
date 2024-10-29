// Problem-2684: Maximum Number of Moves in a Grid

// You are given a 0-indexed m x n matrix grid consisting of positive integers.
// You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
// Return the maximum number of moves that you can perform.
// Example:
// Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
// Output: 3
// Explanation: We can start at the cell (0, 0) and make the following moves:
// - (0, 0) -> (0, 1).
// - (0, 1) -> (1, 2).
// - (1, 2) -> (2, 3).
// It can be shown that it is the maximum number of moves that can be made.

class Solution {
public:
    int m;
    int n;
    vector<int> directions = {-1, 0, 1};

    int DFS(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& t) {
        if (t[row][col] != -1) {
            return t[row][col];
        }

        int moves = 0;
        for (int &dir : directions) {
            int newRow = row + dir;
            int newCol = col + 1;

            if (newRow >= 0 && newRow < m && newCol < n && grid[newRow][newCol] > grid[row][col]) {
                moves = max(moves, 1 + DFS(newRow, newCol, grid, t));
            }
        }
        
        t[row][col] = moves;
        return t[row][col];
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;

        vector<vector<int>> t(m, vector<int>(n, -1));

        for (int row = 0; row < m; row++) {
            result = max(result, DFS(row, 0, grid, t));
        }
        return result;
    }
};