// Problem-268: Missing Number

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Example 1:
// Input: nums = [3,0,1]
// Output: 2
// Explanation:
// n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

// Concept: Using the formula for the sum of the first n natural numbers to find the missing number and subtracting the sum of the given array from it. But it causes leakage if n is too large
// So in the loop itself add i and subtract nums[i] from the sum variable.


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        for(int i = 0; i < n; ++i){
            ans += i;
            ans -= nums[i];
        }
        
        return ans;
    }
};