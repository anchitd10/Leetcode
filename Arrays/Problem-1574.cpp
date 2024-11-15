// Problem-1574: Shortest Subarray to be Removed to Make Array Sorted

// Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
// Return the length of the shortest subarray to remove.
// A subarray is a contiguous subsequence of the array.
// Example 1:
// Input: arr = [1,2,3,10,4,2,3,5]
// Output: 3
// Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
// Another correct solution is to remove the subarray [3,10,4].

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // jth pointer from right side
        int j = n-1;
        while(j>0 && arr[j] >= arr[j-1]){
            j--;
        }

        int i=0;
        int result = j;

        //find deleted elements (j-i-1)
        while(i<j && (i==0 || arr[i] >= arr[i-1])){
            while(j<n && arr[i] > arr[j]){
                j++;
            }

            // arr[i] <= arr[j] for correct i and j
            result = min(result, j-i-1);
            i++;
        }
        return result;
    }
};