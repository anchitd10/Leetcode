// Problem-1568: Minimum Number of Days to Disconnect Island

// You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
// The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
// In one day, we are allowed to change any single land cell (1) into a water cell (0).
// Return the minimum number of days to disconnect the grid.
// Example:
// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 2
// Explanation: We need at least 2 days to get a disconnected grid.
// Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

class Solution {
public:
    int m,n;

    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&vis){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] == true || grid[i][j] == 0){
            return;
        }
        vis[i][j] = true;  //mark land as visited

        DFS(grid, i+1, j, vis);
        DFS(grid, i-1, j, vis);
        DFS(grid, i, j+1, vis);
        DFS(grid, i, j-1, vis);
    }

    int numberOfIslandsUtil(vector<vector<int>>& grid){
        int islands=0;
        vector<vector<bool>> vis(m, vector<bool>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    DFS(grid, i, j, vis);
                    islands++;
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        int islands=numberOfIslandsUtil(grid);
        if(islands > 1 || islands == 0){
            return 0;
        }
        else{
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == 1){
                        grid[i][j]=0;

                        islands = numberOfIslandsUtil(grid);

                        if(islands > 1 || islands == 0){
                            return 1;
                        }
                        grid[i][j] = 1;  //to reset to land again
                    }
                }
            }
        }
        return 2;
    }
};