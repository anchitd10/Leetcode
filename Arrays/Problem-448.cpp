// Problem-448: Find All Numbers Disappeared in an Array

// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:
// Input: nums = [1,1]
// Output: [2]


// Concept: Using the input array itself to mark the presence of numbers by negating the value at the index corresponding to each number found. Then, the indices which have positive values correspond to the missing numbers.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int idx = abs(nums[i]) - 1;

            if(nums[idx] < 0) continue;
            nums[idx] *= -1;
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};