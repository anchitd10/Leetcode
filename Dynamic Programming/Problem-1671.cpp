// Problem-1671: Minimum Number of Removals to Make Mountain Array

// You may recall that an array arr is a mountain array if and only if:
// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.
// Example:
// Input: nums = [2,1,1,5,6,2,3,1]
// Output: 3
// Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS(n,1);
        vector<int> LDS(n,1);

        //longest increasing subsequence
        for(int i=0; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }
        }

        //longest decreasing subsequence
        for(int i=n-1; i>=0; i--){
            for(int j= i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int minRemoval = INT_MAX;
        for(int i=0; i<n; i++){
            if(LIS[i] > 1 && LDS[i] >1){
                minRemoval = min(minRemoval, n - LIS[i] - LDS[i] + 1);
            }
        }
        return minRemoval;
    }
};