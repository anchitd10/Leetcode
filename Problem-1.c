// Problem-1: Two Sums

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* retarr=malloc(2*sizeof(int));
    retarr[0]=1;
    retarr[1]=1;
    for(int i=0;i<numsSize;++i){
        for(int j=i+1;j<numsSize;++j){
            if(nums[i]+nums[j]==target){
                *returnSize=2;
                retarr[0]=i;
                retarr[1]=j;
                return retarr;
            }
        }
    }
    *returnSize=0;
    return NULL;
}