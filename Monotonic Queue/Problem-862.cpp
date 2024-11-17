// Problem-862: Shortest Subarray with Sum at Least K

// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [1], k = 1
// Output: 1
// Example 2:
// Input: nums = [1,2], k = 4
// Output: -1
// Example 3:
// Input: nums = [2,-1,2], k = 3
// Output: 3

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> deq;

        vector<long long> cumulativeSum(n,0);

        int result = INT_MAX;
        int i = 0;

        while(i < n){
            if(i == 0){
                cumulativeSum[i] = nums[i];
            }
            else{
                cumulativeSum[i] = cumulativeSum[i-1] + nums[i];
            }

            if(cumulativeSum[i] >= k){
                result = min(result, i+1);
            }

            while(!deq.empty() && cumulativeSum[i] - cumulativeSum[deq.front()] >= k){
                result = min(result, i-deq.front());
                deq.pop_front();
            }

            while(!deq.empty() && cumulativeSum[i] <= cumulativeSum[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(i);
            i++;
        }
        return result == INT_MAX ? -1 : result;
    }
};