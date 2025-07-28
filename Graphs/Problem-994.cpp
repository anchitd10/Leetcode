// Problem-994: Rotting Oranges

// You are given an m x n grid where each cell can have one of three values:
// - 0 representing an empty cell,
// - 1 representing a fresh orange, or
// - 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // {(row, column), time}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int tm = 0;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for(int i=0; i<4; i++){
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m
                && vis[nRow][nCol]!=2 && grid[nRow][nCol] == 1){
                    q.push({{nRow, nCol}, t+1});
                    vis[nRow][nCol] = 2;
                }
            }
        }

        // check if all oranges are rotten
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return tm;
    }
};