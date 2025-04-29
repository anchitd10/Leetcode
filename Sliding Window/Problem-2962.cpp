// Problem-2962: Count Subarrays Where Max Element Appears at Least K Times

// You are given an integer array nums and a positive integer k.
// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
// A subarray is a contiguous sequence of elements within an array.
// Example 1:
// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(begin(nums), end(nums));
        
        int n = nums.size();
        int i = 0, j = 0;
        
        long long result = 0;
        int countMax = 0;
        
        while(j < n) {
            if(nums[j] == maxE) {
                countMax++;
            }
            
            while(countMax >= k) {
                result += n-j;
                
                if(nums[i] == maxE) {
                    countMax--;
                }
                i++;
            }
            j++;
        }
        
        return result;
    }
};