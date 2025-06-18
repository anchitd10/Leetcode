// Problem-2966: Divide Array Into Arrays With Max Difference

// You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
// Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
// - The difference between any two elements in one array is less than or equal to k.
// Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.
// Example 1:
// Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
// Output: [[1,1,3],[3,4,5],[7,8,9]]
// Explanation:
// The difference between any two elements in each array is less than or equal to 2.


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(begin(nums), end(nums));

        for(int i=0; i<n; i += 3){
            if(nums[i+2] - nums[i] > k){
                return {};
            }
            else{
                result.push_back({nums[i], nums[i+1], nums[i+2]});
            }
        }

        return result;
    }
};