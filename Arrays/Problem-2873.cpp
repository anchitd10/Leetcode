// Problem-2873: Maximum Value of an Ordered Triplet I

// You are given a 0-indexed integer array nums.
// Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
// The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].
// Example 1:
// Input: nums = [12,6,1,2,7]
// Output: 77
// Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
// It can be shown that there are no ordered triplets of indices with a value greater than 77. 


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMax_i(n);
        vector<int> rightMax_k(n);

        for (int j = 1; j < n; j++) {
            leftMax_i[j] = max(leftMax_i[j - 1], nums[j - 1]);
        }

        for (int j = n - 2; j >= 0; j--) {
            rightMax_k[j] = max(rightMax_k[j + 1], nums[j + 1]);
        }

        long long result = 0;
        for (int j = 1; j < n; j++) {
            result = max(result, (long long)(leftMax_i[j] - nums[j]) * rightMax_k[j]);
        }
        return result;
    }
};