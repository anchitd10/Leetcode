// Problem-75: Sort Colors

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.
// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Concept: Dutch National Flag Algorithm
// Tip: Maintain three pointers low, mid, and high. low and mid start from the
// beginning of the array and high starts from the end of the array. If the mid
// pointer points to 0, swap the elements at low and mid and increment both pointers.
// If the mid pointer points to 1, increment the mid pointer. If the mid pointer
// points to 2, swap the elements at mid and high and decrement the high pointer.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid  = 0;
        int high = n-1;
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++, mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};