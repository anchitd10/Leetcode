// Problem-594: Longest Harmonious Subsequence

// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
// Example 1:
// Input: nums = [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation:
// The longest harmonious subsequence is [3,2,2,2,3].


class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int result = 0;

        for(int &num : nums){
            mp[num]++;
        }

        for(int &num : nums){
            int minNum = num;
            int maxNum = num + 1;

            if(mp.count(maxNum)){
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }

        return result;
    }
};