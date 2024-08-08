// Problem-885: Spiral Matrix III

// You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
// You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
// Return an array of coordinates representing the positions of the grid in the order you visited them.
// Example:
// Input: rows = 1, cols = 4, rStart = 0, cStart = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = rows * cols;
        vector<vector<int>> res(n, vector<int>(2));
        res[0][0] = rStart;
        res[0][1] = cStart;
        int count = 1;
        int step = 1;
        int index = 0;
        
        while (count < n) {
            for (int times = 0; times < 2; times++) {
                int dr = directions[index % 4][0];
                int dc = directions[index % 4][1];
                for (int i = 0; i < step; i++) {
                    rStart += dr;
                    cStart += dc;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        res[count][0] = rStart;
                        res[count][1] = cStart;
                        count++;
                    }
                }
                index++;
            }
            step++;
        }
        
        return res;
    }
};