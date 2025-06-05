// Problem-229: Majority Element II

// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// Example 1:
// Input: nums = [3,2,3]
// Output: [3]


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto i : mp){
            if(i.second > n/3){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};