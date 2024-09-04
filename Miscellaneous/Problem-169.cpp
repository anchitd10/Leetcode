// Problem-169: Majority Element

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Example:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size()/2;

        for(auto i : nums){
            count[i]++;
        }
        int ans = 0;

        for(auto i : count){
            if(i.second > n){
                ans = i.first;
            }
        }
        return ans;
    }
};