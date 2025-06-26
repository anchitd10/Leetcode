// Problem-974: Subarray Sums Divisible by K

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]



class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // brute force- O(n^2)
        int n = nums.size();
        int count = 0;

        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = (i == 0) ? nums[j] : nums[j] - nums[i - 1];

                if (sum % k == 0) {
                    count++;
                }
            }
        }

        return count++;
    }
};