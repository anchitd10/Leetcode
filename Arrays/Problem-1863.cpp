// Problem-1863: Sum of All Subset XOR Totals

// The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
// - For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// Given an array nums, return the sum of all XOR totals for every subset of nums. 
// Note: Subsets with the same elements should be counted multiple times.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
// Example:
// Input: nums = [5,1,6]
// Output: 28
// Explanation: The 8 subsets of [5,1,6] are:
// - The empty subset has an XOR total of 0.
// - [5] has an XOR total of 5.
// - [1] has an XOR total of 1.
// - [6] has an XOR total of 6.
// - [5,1] has an XOR total of 5 XOR 1 = 4.
// - [5,6] has an XOR total of 5 XOR 6 = 3.
// - [1,6] has an XOR total of 1 XOR 6 = 7.
// - [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
// 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28


class Solution {
public:
    void solve(vector<int>&nums, int i, vector<int>& currSubset, vector<vector<int>>& subsets){
        if(i == nums.size()){
            subsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[i]);
        solve(nums, i+1, currSubset, subsets);
        currSubset.pop_back();
        solve(nums, i+1, currSubset, subsets);
    }


    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;

        vector<int> currSubset;
        solve(nums, 0, currSubset, subsets);

        int result = 0;
        for(vector<int>& subset : subsets){
            int XOR = 0;
            for(int &num : subset){
                XOR ^= num;
            }

            result += XOR;
        }

        return result; 
    }
};