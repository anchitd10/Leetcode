// Problem-689: Maximum Sum of 3 Non-Overlapping Subarrays

// Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
// Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
// Example 1:
// Input: nums = [1,2,1,2,6,7,5,1], k = 2
// Output: [0,3,5]
// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n - k + 1, 0); // sum of each subarray of size k
        vector<int> left(n - k + 1, 0); // best starting index for left subarray
        vector<int> right(n - k + 1, 0); // best starting index for right subarray
        
        // sums of all subarrays of size k
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            currentSum += nums[i];
            if (i >= k) currentSum -= nums[i - k];
            if (i >= k - 1) sums[i - k + 1] = currentSum;
        }
        
        // left array
        int bestLeftIndex = 0;
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] > sums[bestLeftIndex]) {
                bestLeftIndex = i;
            }
            left[i] = bestLeftIndex;
        }
        
        // right array
        int bestRightIndex = sums.size() - 1;
        for (int i = sums.size() - 1; i >= 0; --i) {
            if (sums[i] >= sums[bestRightIndex]) {
                bestRightIndex = i;
            }
            right[i] = bestRightIndex;
        }
        
        // maximum sum by iterating over middle subarrays
        vector<int> result(3, -1);
        int maxSum = 0;
        for (int middle = k; middle < sums.size() - k; ++middle) {
            int l = left[middle - k];
            int r = right[middle + k];
            int totalSum = sums[l] + sums[middle] + sums[r];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {l, middle, r};
            }
        }
        
        return result;
    }
};