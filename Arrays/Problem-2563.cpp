// Problem-2563: Count the Number of Fair Pairs

// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
// A pair (i, j) is fair if:
// 0 <= i < j < n, and
// lower <= nums[i] + nums[j] <= upper
//  Example 1:
// Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
// Output: 6
// Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

// Brute Force---> for every i check next j elements and see if between sum range

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums), end(nums));
        long long result = 0;

        for(int i=0; i<n; i++){
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i])-begin(nums); //first element not less than (lower-nums[i])
            int x = idx - 1 - i;

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums); // first element not greater than (upper-nums[i])
            int y = idx - 1 - i;

            result += (y-x);
        }
        return result;
    }
};