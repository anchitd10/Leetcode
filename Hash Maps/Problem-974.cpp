// Problem-974: Subarray Sums Divisible by K

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         // brute force- O(n^2)
//         int n = nums.size();
//         int count = 0;

//         for (int i = 1; i < n; i++) {
//             nums[i] += nums[i - 1];
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int sum = (i == 0) ? nums[j] : nums[j] - nums[i - 1];

//                 if (sum % k == 0) {
//                     count++;
//                 }
//             }
//         }

//         return count++;
//     }
// };



// Approach-2 using hashmap
// if all array elements sum is divisible by k and its elements of subaray of size m is also divisible by k then the remaining n-m elements will also be divisible by k
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            
            int rem = sum%k;
            
            if(rem < 0) {
                rem += k;
            }
            
            if(mp.find(rem) != mp.end()) {
                result += mp[rem];
            }
            
            mp[rem]++;
            
        }
        
        return result;
        
    }
};