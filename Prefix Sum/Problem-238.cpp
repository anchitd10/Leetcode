// Problem-238: Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.
// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// 1 approach if division operation is allowed: just take product of all elements and divide by specific element at its position


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;
        right[n-1] = 1;

        for(int i=1; i<n; i++){
            left[i] = nums[i-1] * left[i-1];
        }

        for(int i=n-2; i>=0; i--){
            right[i] = nums[i+1] * right[i+1];
        }

        vector<int> result(n);
        for(int i=0; i<n; i++){
            result[i] = left[i] * right[i];
        }

        return result;
    }
};