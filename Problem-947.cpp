// Problem-947: Most Stones Removed with Same Row or Column

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
// Example:
// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int n;

    int find(int i){
        if(parent[i] != i){
            parent[i] = find(parent[i]);
        }
        return parent[i]; 
    }

    void Union(int i, int j){
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j){
            if(rank[root_i] > rank[root_j]){
                parent[root_j] = root_i;
            }
            else if(rank[root_i] < rank[root_j]){
                parent[root_i] = root_j;
            }
            else{
                parent[root_j] = root_i;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i,j); 
                }
            }
        }
        int groups = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i){
                groups++;
            }
        }
        return n-groups;
    }
};