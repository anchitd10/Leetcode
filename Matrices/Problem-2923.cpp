// Problem-2923: Find Champion I

// There are n teams numbered from 0 to n - 1 in a tournament.
// Given a 0-indexed 2D boolean matrix grid of size n * n. For all i, j that 0 <= i, j <= n - 1 and i != j team i is stronger than team j if grid[i][j] == 1, otherwise, team j is stronger than team i.
// Team a will be the champion of the tournament if there is no team b that is stronger than team a.
// Return the team that will be the champion of the tournament.
// Example 1:
// Input: grid = [[0,1],[0,0]]
// Output: 0
// Explanation: There are two teams in this tournament.
// grid[0][1] == 1 means that team 0 is stronger than team 1. So team 0 will be the champion.

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
            if(count == n-1){
                return i;
            }
        }
        return -1;
    }
};