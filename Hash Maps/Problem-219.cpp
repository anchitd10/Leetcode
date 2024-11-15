// Problem-219: Contains Duplicate II

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example:
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end() && abs(mp[nums[i]] - i) <= k){
                return true;
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};
