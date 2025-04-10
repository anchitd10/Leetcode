// Problem-1800: Maximum Ascending Subarray Sum

// Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
// A subarray is defined as a contiguous sequence of numbers in an array.
// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.
// Example 1:
// Input: nums = [10,20,30,5,10,50]
// Output: 65
// Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = currentSum;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) { // extend ascending subarray
                currentSum += nums[i];
            } else { // new subarray
                currentSum = nums[i];
            }
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};