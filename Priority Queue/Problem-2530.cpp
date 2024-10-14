// Problem-2530: Maximal Score after applying K operations

// You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
// In one operation:
// choose an index i such that 0 <= i < nums.length, increase your score by nums[i], and replace nums[i] with ceil(nums[i] / 3).
// Return the maximum possible score you can attain after applying exactly k operations.
// The ceiling function ceil(val) is the least integer greater than or equal to val.
// Example 1:
// Input: nums = [10,10,10,10,10], k = 5
// Output: 50
// Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;

        priority_queue<int> pq(begin(nums), end(nums));

        while(k--){
            int maxElement = pq.top();
            pq.pop();

            sum += maxElement;
            maxElement = ceil(maxElement/3.0);
            pq.push(maxElement);
        }
        return sum;
    }
};