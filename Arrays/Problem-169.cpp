// Problem-169: Majority Element

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Example 1:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // either use brute force to check freq and then return the largest one
        //2nd approach

        int n = nums.size();
        sort(begin(nums), end(nums));
        return nums[n/2];
    }
};