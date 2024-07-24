// Problem-2191: Sort the Jumbled Numbers

// You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.
// The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.
// You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.
// Notes:
// Elements with the same mapped values should appear in the same relative order as in the input.
// The elements of nums should only be sorted based on their mapped values and not be replaced by them.
// Example 1:
// Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
// Output: [338,38,991]
// Explanation: 
// Map the number 991 as follows:
// 1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
// 2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
// Therefore, the mapped value of 991 is 669.
// 338 maps to 007, or 7 after removing the leading zeros.
// 38 maps to 07, which is also 7 after removing leading zeros.
// Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
// Thus, the sorted array is [338,38,991].

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<long long, vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            vector<int> temp;
            int x=nums[i];
            if(x==0){
                mp[mapping[x]].push_back(x);
                continue;
            }
            while(x){
                temp.push_back(x%10);
                x/=10;
            }
            long long num=0;
            for(int j=temp.size()-1; j>=0; j--){
                num= (num*10) + mapping[temp[j]];
            }
            mp[num].push_back(nums[i]);
        }
        vector<int> ans;
        for(auto it : mp){
            for(auto x : it.second){
                ans.push_back(x);
            }
        }
        return ans;
    }
};