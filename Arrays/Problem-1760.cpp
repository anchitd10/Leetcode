// Problem-1760: Minimum Limit of Balls in a Bag

// You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.
// You can perform the following operation at most maxOperations times:
// Take any bag of balls and divide it into two new bags with a positive number of balls.
// For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
// Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.
// Return the minimum possible penalty after performing the operations.
// Example 1:
// Input: nums = [9], maxOperations = 2
// Output: 3
// Explanation: 
// - Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
// - Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
// The bag with the most number of balls has 3 balls, so your penalty is 3 and you should 

// Array- Binary Search (Minimise the max)

class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOps, int mid){
        int totalOps = 0;

        for(int &num : nums){
            int ops = num/mid;

            if(num % mid == 0){
                ops -= 1;
            }
            totalOps += ops;
        }
        return totalOps <= maxOps;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(begin(nums), end(nums));

        int result = r;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPossible(nums, maxOperations, mid) == true){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return result;
    }
};