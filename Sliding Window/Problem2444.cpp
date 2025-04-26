// Problem-2444: Count Subarrays With Fixed Bounds

// You are given an integer array nums and two integers minK and maxK.
// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
// - The minimum value in the subarray is equal to minK.
// - The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
// Example 2:
// Input: nums = [1,1,1,1], minK = 1, maxK = 1
// Output: 10
// Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int n = nums.size();
        int minKPos = -1;
        int maxKPos = -1;
        int culpritIdx = -1;

        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                culpritIdx = i;
            }

            if(nums[i] == minK){
                minKPos = i;
            }

            if(nums[i] == maxK){
                maxKPos = i;
            }

            // here we found the base subarray that must contain the min and max said element but now we will get all remaining elements between the smaller position and position of the culprit element.
            // so if temp is -ve it means culprit element is already between base subarray
            // if temp is positive then that many elements can also form a new subarray
            long long smaller = min(minKPos, maxKPos);
            long long temp = smaller - culpritIdx;

            ans += (temp <= 0) ? 0: temp;
        }

        return ans;
    }
};