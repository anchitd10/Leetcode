// Problem-2554: Maximum Number of Integers to Choose From a Range I

// You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
// The chosen integers have to be in the range [1, n].
// Each integer can be chosen at most once.
// The chosen integers should not be in the array banned.
// The sum of the chosen integers should not exceed maxSum.
// Return the maximum number of integers you can choose following the mentioned rules.
// Example 1:
// Input: banned = [1,6,5], n = 5, maxSum = 6
// Output: 2
// Explanation: You can choose the integers 2 and 4.
// 2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        int currentSum = 0;
        int count = 0;

        for (int i = 1; i <= n; ++i) {
            if (bannedSet.count(i)) continue; // skip banned numbers
            if (currentSum + i > maxSum) break; // stop if adding `i` exceeds maxSum
            currentSum += i;
            ++count;
        }

        return count;
    }
};