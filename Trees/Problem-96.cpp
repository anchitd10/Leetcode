// Problem-96: Unique Binary Search Trees

// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// Example 1:
// Input: n = 3
// Output: 5


class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n <= 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += solve(i-1, dp) * solve(n-i, dp);
        }

        return dp[n] = ans;
    }

    int numTrees(int n) {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};