// Problem-189: Rotate Array

// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  // to handle cases where k > n

        reverse(nums.begin(), nums.end());

        // rotate first k elements(the ones that got placed in the start now)
        reverse(nums.begin(), nums.begin() + k);

        // rotate the remaining ones
        reverse(nums.begin() + k, nums.end());
    }
};