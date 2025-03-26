// Problem-2033: Minimum Operations to Make a Uni-Value Grid

// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
// A uni-value grid is a grid where all the elements of it are equal.
// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
// Example 1:
// Input: grid = [[2,4],[6,8]], x = 2
// Output: 4
// Explanation: We can make every element equal to 4 by doing the following: 
// - Add x to 2 once.
// - Subtract x from 6 once.
// - Subtract x from 8 twice.
// A total of 4 operations were used.
// Example 2:
// Input: grid = [[1,5],[2,3]], x = 1
// Output: 5
// Explanation: We can make every element equal to 3.


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        vector<int> vec;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vec.push_back(grid[i][j]);
            }
        }

        int L = vec.size();

        sort(begin(vec), end(vec));

        int target = vec[L/2];

        for(int &num : vec){
            if(num % x != target % x){
                return -1;
            }

            result += abs(target-num)/x;
        }

        return result;
    }
};