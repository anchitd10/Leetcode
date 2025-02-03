// Problem-3105: Longest Strictly Increasing or Strictly Decreasing Subarray

// You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.
// Example 1:
// Input: nums = [1,4,3,3,2]
// Output: 2
// Explanation:
// The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
// The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
// Hence, we return 2.

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1, inc = 1, dec = 1;
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                inc++;
                dec = 1;
            }
            else if(nums[i] < nums[i-1]){
                dec++;
                inc = 1;
            }
            else{
                inc = 1;
                dec = 1;
            }
            maxLen = max({maxLen, inc, dec});
        }
        return maxLen;
    }
};