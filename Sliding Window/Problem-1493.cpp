// Problem-1493: Longest Subarray of 1's After Deleting One Element

// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
// Example 1:
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.



// Brute Force
class Solution {
public:
    int n;

    int findMax(vector<int>& nums, int skipIdx){
        int currLen = 0;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            if(i == skipIdx){
                continue;
            }

            if(nums[i] == 1){
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            else{
                currLen = 0;
            }
        }

        return maxLen;
    }

    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        int result = 0;
        int zeroCount = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                zeroCount++;
                result = max(result, findMax(nums, i));
            }
        }

        if(zeroCount == 0){
            return n-1;
        }

        return result;
    }
};


// Sliding Window
class Solution {
public:
    int n;

    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        int i = 0;
        int countZero = 0;
        int maxLen = 0;

        for(int j=0; j<n; j++){
            if(nums[j] == 0){
                countZero++;
            }

            while(countZero > 1){
                if(nums[i] == 0){
                    countZero--;
                }
                i++;
            }

            maxLen = max(maxLen, j-i);     // here we are taking j-i instead of ususal j-i+1 because we need at that one element to be removed
        }

        return maxLen;
    }
};