// Problem-3201: Find the Maximum Length of Valid Subsequence I

// You are given an integer array nums.
// A subsequence sub of nums with length x is called valid if it satisfies:
// - (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
// Return the length of the longest valid subsequence of nums.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// Example 1:
// Input: nums = [1,2,3,4]
// Output: 4
// Explanation:
// The longest valid subsequence is [1, 2, 3, 4].
// Example 2:
// Input: nums = [1,2,1,1,2,1,2]
// Output: 6
// Explanation:
// The longest valid subsequence is [1, 2, 1, 2, 1, 2].


// concept for the solution:
// 1. A valid subsequence has the property that the sum of any two consecutive elements has the same parity.
// 2. This means that all even numbers can be grouped together and all odd numbers can be grouped together.
// 3. The maximum length of a valid subsequence is the max of either the count of even numbers or the count of odd numbers in the array or the subsequence of the alternating elements.

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int evenCount = 0;
        int oddCount = 0;
        
        for(int num : nums){
            if(num % 2 == 0){
                evenCount++;
            }
            else{
                oddCount++;
            }
        }

        int parity = nums[0] % 2;
        int alternating = 1;

        for(int i=1; i<n; i++){
            int currParity = nums[i] % 2;

            if(currParity != parity){
                alternating++;
                parity = currParity;
            }
        }

        return max({evenCount, oddCount, alternating});
    }
};