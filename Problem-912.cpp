// Problem-912: Sort the Array

// Given an array of integers nums, sort the array in ascending order and return it.
// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
// Example 1:
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).


// Counting Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int i=0;

        for(int &num: nums){
            mp[num]++;
        }

        int minElement = *min_element(begin(nums), end(nums));
        int maxElement = *max_element(begin(nums), end(nums));

        for(int k=minElement; k<=maxElement; k++){
            while(mp[k] > 0){
                nums[i] = k;
                i++;
                mp[k]--;
            }
        }
        return nums;
    }
};