// Problem-2044: Count Number of Maximum Bitwise-OR Subsets

// Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
// The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).
// Example 1:
// Input: nums = [3,1]
// Output: 2
// Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
// - [3]
// - [3,1]

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, count = 0;

        // find the maximum possible OR value
        for (int num : nums) {
            maxOr |= num;
        }

        // use backtracking to count how many subsets have this OR value
        function<void(int, int)> backtrack = [&](int index, int currentOr) {
            if (index == nums.size()) {
                if (currentOr == maxOr) {
                    count++;
                }
                return;
            }
            
            // include the current element in the subset
            backtrack(index + 1, currentOr | nums[index]);
            
            // exclude the current element from the subset
            backtrack(index + 1, currentOr);
        };

        backtrack(0, 0);

        return count;
    }
};
