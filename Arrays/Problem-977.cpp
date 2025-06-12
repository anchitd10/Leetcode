// Problem-977: Squares of a Sorted Array

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].



// 2 pointer approach
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int k = n - 1;

        int i = 0, j = n - 1;

        vector<int> result(n,0);

        while (k >= 0) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];

            if(a > b){
                result[k] = a;
                i++;
            }
            else{
                result[k] = b;
                j--;
            }

            k--;
        }

        return result;
    }
};