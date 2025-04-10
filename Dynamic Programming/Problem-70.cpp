// Problem-70: CLimbing Stairs

// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step


// Brute Force - Recursion:Memoization - Top-Down
class Solution {
public:
    int t[50];
    int solve(int n){
        if(n < 0){
            return 0;
        }

        if(t[n] != -1){
            return t[n];
        }

        if(n == 0){
            return 1;
        }

        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return t[n] = one_step + two_step;
    }

    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};


// Space Optimised - Bottom-Up
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n ==3){
            return n;
        }

        vector<int> arr(n+1);

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i=3; i<=n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        
        return arr[n];
    }
};