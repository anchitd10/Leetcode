// Problem-3152: Special Array II

// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
// You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
// subarray   ----->   nums[fromi..toi] is special or not.
// Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
// Example 1:
// Input: nums = [3,4,1,2,6], queries = [[0,4]]
// Output: [false]
// Explanation:
// The subarray is [3,4,1,2,6]. 2 and 6 are both even.

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> specialPrefix(n, 0);

        for (int i = 0; i < n - 1; ++i) {
            specialPrefix[i] = (nums[i] % 2 != nums[i + 1] % 2) ? 1 : 0;
        }

        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + specialPrefix[i - 1];
        }

        vector<bool> result;

        for (const auto& query : queries) {
            int fromi = query[0], toi = query[1];
            if (toi - fromi == 0) {
                result.push_back(true);
            } else {
                int specialCount = prefixSum[toi] - prefixSum[fromi];
                result.push_back(specialCount == (toi - fromi));
            }
        }

        return result;
    }
};
