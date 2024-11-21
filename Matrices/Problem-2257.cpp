// Problem-2257: Count Unguarded Cells in the Grid

// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
// Return the number of unoccupied cells that are not guarded.
// Example:
// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output: 7
// Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.

class Solution {
public:
    void markGuarded(int row, int col, vector<vector<int>>& grid){
        //up
        for(int i=row-1; i>=0; i--){
            if(grid[i][col] == 2 || grid[i][col] == 3){
                break;
            }
            grid[i][col] = 1; //mark as guarded
        }

        //down
        for(int i=row+1; i<grid.size(); i++){
            if(grid[i][col] == 2 || grid[i][col] == 3){
                break;
            }
            grid[i][col] = 1;
        }

        //left
        for(int j=col-1; j>=0; j--){
            if(grid[row][j] == 2 || grid[row][j] == 3){
                break;
            }
            grid[row][j] = 1;
        }

        //right
        for(int j = col+1; j < grid[0].size(); j++){
            if(grid[row][j] == 2 || grid[row][j] == 3){
                break;
            }
            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,0));

        //mark guarded positions
        for(vector<int>& vec : guards){
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2;  //guard
        }

        //mark wall positions
        for(vector<int>& vec : walls){
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3;  //wall
        }

        for(vector<int>& guard : guards){
            int i = guard[0];
            int j = guard[1];
            markGuarded(i,j,grid);
        }

        int count = 0;
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};