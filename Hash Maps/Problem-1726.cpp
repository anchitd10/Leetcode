// Problem-1726: Tuple with Same Product

// Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.
// Example 1:
// Input: nums = [2,3,4,6]
// Output: 8
// Explanation: There are 8 valid tuples:
// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
// Example 2:
// Input: nums = [1,2,4,5,10]
// Output: 16
// Explanation: There are 16 valid tuples:
// (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
// (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
// (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
// (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)



// Brute Force
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuples = 0;

        sort(begin(nums), end(nums));

        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                for(int k=i+1; k<j; k++){
                    for(int l=j-1; l>k; l--){
                        int p1 = nums[i] * nums[j];
                        int p2 = nums[k] * nums[l];

                        if(p1 == p2){
                            tuples++;
                        }
                    }
                }
            }
        }
        return tuples * 8;
    }
};