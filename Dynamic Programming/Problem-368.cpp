// Problem-368: Largest Divisible Subset

// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
// - answer[i] % answer[j] == 0, or
// - answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.
// Example 1:
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:
// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
        int maxi = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxi]){
                maxi = i;
            }
        }

        vector<int> res;
        for (int i = maxi; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
        }

        return res;
    }
};