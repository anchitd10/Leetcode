// Problem-3375: Minimum Operations to Make Array Values Equal to K

// You are given an integer array nums and an integer k.
// An integer h is called valid if all values in the array that are strictly greater than h are identical.
// For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.
// You are allowed to perform the following operation on nums:
// - Select an integer h that is valid for the current values in nums.
// - For each index i where nums[i] > h, set nums[i] to h.
// Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.
// Example 1:
// Input: nums = [5,2,5,4,5], k = 2
// Output: 2
// Explanation:
// The operations can be performed in order using valid integers 4 and then 2.
// Example 2:
// Input: nums = [2,1,2], k = 2
// Output: -1
// Explanation:
// It is impossible to make all the values equal to 2.


// Logic:
// (1). We first take the second highest element(valid number) in the array and convert the highest identical elements to the current valid number.
// (2). We then go in decreasing order of the elements in the array until all the elements are equal to the latest valid number i.e k.
// (3). So by this logic the number of operations = number of unique elements present greater than k(latest valid number)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> unique;

        for(int &x : nums){
            if(x < k){
                return -1;
            }
            if(x > k){
                unique.insert(x);
            }
        }
        return unique.size();
    }
};