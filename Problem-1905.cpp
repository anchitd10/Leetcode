// Problem-1905: Count Sub Islands

// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.
// Example:
// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output: 3
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.


//DFS
class Solution {
public:
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[0].size()){
            return true;
        }

        if(grid2[i][j] != 1){
            return true;
        }

        grid2[i][j] = -1; //mark visited

        bool result = (grid1[i][j] == 1);   //grid1[i][j] must have 1 as well only then subisland
        result = result & checkSubIsland(grid1, grid2, i+1, j);  //down
        result = result & checkSubIsland(grid1, grid2, i-1, j);  //up
        result = result & checkSubIsland(grid1, grid2, i, j+1);  //right
        result = result & checkSubIsland(grid1, grid2, i, j-1);  //left

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //DFS
        int subIslands = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)){
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
};