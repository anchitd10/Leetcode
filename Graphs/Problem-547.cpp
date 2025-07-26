// Problem-547: Number of Provinces

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis){
        vis[node] = 1;
        for(int it : adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);
        
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        
        vector<int> vis(V, 0);
        int count = 0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                count++;
                dfs(i, adjLs, vis);
            }
        }
        
        return count;
    }
};