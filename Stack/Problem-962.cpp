// Problem-962: Maximum Width Ramp

// A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
// Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.
// Example 1:
// Input: nums = [6,0,8,2,1,5]
// Output: 4
// Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack;
        int maxWidth = 0;
        
        //decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            //if nums[i] is smaller than the element at stack's top index
            if (stack.empty() || nums[stack.back()] > nums[i]) {
                stack.push_back(i);
            }
        }
        
        for (int j = n - 1; j >= 0; --j) {
            //nums[j] is greater than or equal to nums[stack.back()]
            while (!stack.empty() && nums[j] >= nums[stack.back()]) {
                int i = stack.back();
                stack.pop_back();
                maxWidth = max(maxWidth, j - i);
            }
        }
        
        return maxWidth;
    }
};
