// Problem-264: Ugly Number II

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.
// Example 1:
// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

//dp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;

        for(int i=1; i<n; i++){
            int twoMultiple = dp[p1]*2;
            int threeMultiple = dp[p2]*3;
            int fiveMultiple = dp[p3]*5;

            dp[i] = min(twoMultiple, min(threeMultiple, fiveMultiple));

            if(dp[i] == twoMultiple) p1++;
            if(dp[i] == threeMultiple) p2++;
            if(dp[i] == fiveMultiple) p3++;
        }
        return dp[n-1];

    }
};