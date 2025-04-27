// Problem-3392: Count Subarrays of Length Three With a Condition

// Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
// Example 1:
// Input: nums = [1,2,1,4,1]
// Output: 1
// Explanation:
// Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.


class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=1; i<n-1; i++){
            if(nums[i] == (nums[i-1] + nums[i+1]) * 2){
                count++;
            }
        }
        return count;
    }
};