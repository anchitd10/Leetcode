// Problem-96: Unique Binary Search Trees

// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// Example 1:
// Input: n = 3
// Output: 5

// Concept for top-down dynamic programming approach:
// 1. A binary search tree (BST) can be constructed by choosing each number from 1 to n as the root.
// 2. For each choice of root, the left subtree can be formed using numbers less than the root, and the right subtree using numbers greater than the root.
// 3. The number of unique BSTs for a given n can be computed recursively by summing the products of the number of unique BSTs for the left and right subtrees.
// 4. Use memoization to store results for previously computed values to avoid redundant calculations.

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