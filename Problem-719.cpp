// Problem-719: Find K-th Smallest Pair Distance

// The distance of a pair of integers a and b is defined as the absolute difference between a and b.
// Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
// Example 1:
// Input: nums = [1,3,1], k = 1
// Output: 0
// Explanation: Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.

class Solution {
public:
    bool ok(int mid, vector<int>& a, int k){
        int n = a.size();
        int total = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < n && a[j] - a[i] <= mid) j++;
            total += (j - i - 1);
        }
        return total >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums.front();
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(mid, nums, k))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
