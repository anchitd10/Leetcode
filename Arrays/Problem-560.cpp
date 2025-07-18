// Problem-560: Subarray Sum Equals K

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2



// Brute Force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int s=0; s<n; s++){
            for(int e=s; e<n; e++){
                int sum = 0;
                for(int i=s; i<=e; i++){
                    sum += nums[i];
                }

                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};


// Optimized using HashMap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int count = 0;
        int cumSum = 0;
        mp.insert({0, 1});    // initial cumulative sum

        for(int i=0; i<n; i++){
            cumSum += nums[i];

            if(mp.find(cumSum - k) != mp.end()){
                count += mp[cumSum - k];
            }

            mp[cumSum]++;
        }

        return count;
    }
};