// Problem-2348: Number of Zero-Filled Subarrays

// Given an integer array nums, return the number of subarrays filled with 0.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:
// Input: nums = [1,3,0,0,2,0,0,4]
// Output: 6
// Explanation: 
// There are 4 occurrences of [0] as a subarray.
// There are 2 occurrences of [0,0] as a subarray.
// There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.


// Concept : Find the length of all continuous 0's and then use the formula (n*(n+1))/2 to find the number of subarrays for that length.


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long result = 0;

        while (i < n) {
            long long l = 0;

            if (nums[i] == 0) {
                while (i < n && nums[i] == 0) {
                    i++;
                    l++;
                }
            } else {
                i++;
            }
            result += ((l * (l + 1)) / 2);
        }

        return result;
    }
};