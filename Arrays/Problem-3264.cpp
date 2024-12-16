// Problem-3264: Final Array State After K Multiplication Operations I

// You are given an integer array nums, an integer k, and an integer multiplier.
// You need to perform k operations on nums. In each operation:
// Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
// Replace the selected minimum value x with x * multiplier.
// Return an integer array denoting the final state of nums after performing all k operations.
// Example 1:
// Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
// Output: [8,4,6,5,6]

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        
        while (k > 0) {
            int minIndex = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            nums[minIndex] *= multiplier;
            k--;
        }
        return nums;
    }
};