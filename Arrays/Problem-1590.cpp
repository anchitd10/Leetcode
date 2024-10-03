// Problem-1590: Make Sum Divisible by P

// Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
// Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
// A subarray is defined as a contiguous block of elements in the array.
// Example 1:
// Input: nums = [3,1,4,2], p = 6
// Output: 1
// Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
     int n = nums.size();
        int totalSum = 0;
        
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        if (totalSum % p == 0) {
            return 0;
        }
        
        //sum % p = totalSum % p
        int targetRemainder = totalSum % p;
        unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1; // base case
        
        int currentPrefixSum = 0;
        int minLength = n;
        
        for (int i = 0; i < n; ++i) {
            currentPrefixSum = (currentPrefixSum + nums[i]) % p;
            
            int neededRemainder = (currentPrefixSum - targetRemainder + p) % p;
            
            if (prefixModMap.find(neededRemainder) != prefixModMap.end()) {
                minLength = min(minLength, i - prefixModMap[neededRemainder]);
            }
            prefixModMap[currentPrefixSum] = i;
        }
        return minLength == n ? -1 : minLength;
    }
};