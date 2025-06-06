// Problem-53: Maximum Subarray

// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int i=0; i<n; i++){
            currSum += nums[i];
            maxSum = max(maxSum, currSum);

            if(currSum < 0){
                currSum = 0;
            }
        }
        
        return maxSum;
    }
};