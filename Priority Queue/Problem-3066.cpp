// Problem-3066: Minimum Operations to Exceed Threshold Value II

// You are given a 0-indexed integer array nums, and an integer k.
// You are allowed to perform some operations on nums, where in a single operation, you can:
// - Select the two smallest integers x and y from nums.
// - Remove x and y from nums.
// - Insert (min(x, y) * 2 + max(x, y)) at any position in the array.
// Note that you can only apply the described operation if nums contains at least two elements.
// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.
// Example 1:
// Input: nums = [2,11,10,1,3], k = 10
// Output: 2
// Explanation:
// In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
// In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
// At this stage, all the elements of nums are greater than or equal to 10 so we can stop. 
// It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums));

        int  count = 0;

        while(!pq.empty() && pq.top() < k){
            long smallest = pq.top();
            pq.pop();

            long secondSmallest = pq.top();
            pq.pop();

            pq.push(smallest*2 + secondSmallest);

            count++;
        }
        return count;
    }
};