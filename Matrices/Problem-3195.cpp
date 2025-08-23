// Problem-3195: Find the Minimum Area to Cover All Ones I

// You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
// Return the minimum possible area of the rectangle.
// Example 1:
// Input: grid = [[0,1,0],[1,0,1]]
// Output: 6

// Concept : Just find the min row, max row, min col, max col of all 1's and then calculate the area using these values.


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minRow = n;
        int maxRow = -1;
        int minCol = n;
        int maxCol = -1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};