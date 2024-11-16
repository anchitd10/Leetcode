// Problem-3254: Find the Power of K-Size Subarrays I

// You are given an array of integers nums of length n and a positive integer k.
// The power of an array is defined as:
// Its maximum element if all of its elements are consecutive and sorted in ascending order.
// -1 otherwise.You need to find the power of all subarrays of nums of size k.

// Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].
// Example 1:
// Input: nums = [1,2,3,4,3,2,5], k = 3
// Output: [3,4,-1,-1,-1]
// Explanation:
// There are 5 subarrays of nums of size 3:
// [1, 2, 3] with the maximum element 3.
// [2, 3, 4] with the maximum element 4.
// [3, 4, 3] whose elements are not consecutive.
// [4, 3, 2] whose elements are not sorted.
// [3, 2, 5] whose elements are not consecutive.

//brute force
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> results;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            bool isConsecutive = true;
            int maxElement = nums[i];

            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    isConsecutive = false;
                    break;
                }
                maxElement = max(maxElement, nums[j]);
            }

            if (isConsecutive) {
                results.push_back(maxElement);
            } else {
                results.push_back(-1);
            }
        }

        return results;
    }
};

//second approach also sliding window
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n-k+1, -1);
        int count = 1;

        //first window
        for(int i=1; i<k; i++){
            if(nums[i] == nums[i-1]+1){
                count++;
            }
            else{
                count = 1;
            }
        }
        if(count == k){
            result[0] = nums[k- 1];
        }

        int i=1;
        int j=k;

        //next windows
        while(j < n){
            if(nums[j] == nums[j-1]+1){
                count++;
            }
            else{
                count = 1;
            }

            if(count >= k){
                result[i] = nums[j];
            }

            i++;
            j++;
        }
        return result;
    }
};