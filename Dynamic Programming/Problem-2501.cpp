// Problem-2501: Longest Square Streak in an Array

// You are given an integer array nums. A subsequence of nums is called a square streak if:
// The length of the subsequence is at least 2, and
// after sorting the subsequence, each element (except the first element) is the square of the previous number.
// Return the length of the longest square streak in nums, or return -1 if there is no square streak.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// Example 1:
// Input: nums = [4,3,6,16,8,2]
// Output: 3
// Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
// - 4 = 2 * 2.
// - 16 = 4 * 4.
// Therefore, [4,16,2] is a square streak.
// It can be shown that every subsequence of length 4 is not a square streak.

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        set<long long> numSet(nums.begin(), nums.end());
        int maxStreak = 0;
        
        for (int num : nums) {
            int currentStreak = 1;
            long long currentNum = num;
            
            // find the next square in the streak
            while (numSet.find(currentNum * currentNum) != numSet.end()) {
                currentNum = currentNum * currentNum;
                currentStreak++;
                
                // prevent overflow,
                if (currentNum > 1e9) break;
            }
            
            maxStreak = max(maxStreak, currentStreak);
        }
        
        return (maxStreak >= 2) ? maxStreak : -1;
    }
};