// Problem-407: Trapping Rain Water II

// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
// Example 1:
// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        // pair<int, pair<int, int>> 
        //{height, {r, c}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> vis(n, vector<int>(m));

        //first and last column
        for(int i=0; i<n; i++){
            vis[i][0] = 1;
            vis[i][m-1] = 1;
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m-1], {i, m-1}});
        }
        //first and last row
        for(int i=0; i<m; i++){
            vis[0][i]=1;
            vis[n-1][i]=1;
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[n-1][i], {n-1, i}});
        }
        int ans=0;
        while(!pq.empty()){
            int h = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    ans+=max(0, h-heightMap[nr][nc]);
                    pq.push({max(h, heightMap[nr][nc]), {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};