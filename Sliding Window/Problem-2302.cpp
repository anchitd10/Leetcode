// Problem-2302: Count Subarrays With Score Less Than K

// The score of an array is defined as the product of its sum and its length.
// - For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
// Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.
// A subarray is a contiguous sequence of elements within an array.
// Example 1:
// Input: nums = [2,1,4,3,5], k = 10
// Output: 6
// Explanation
// The 6 subarrays having scores less than 10 are:
// - [2] with score 2 * 1 = 2.
// - [1] with score 1 * 1 = 1.
// - [4] with score 4 * 1 = 4.
// - [3] with score 3 * 1 = 3. 
// - [5] with score 5 * 1 = 5.
// - [2,1] with score (2 + 1) * 2 = 6.
// Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.


// Brute Force
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long count = 0;

        for(int i=0; i<n; i++){
            long long sum = 0;

            for(int j=i; j<n; j++){
                sum += nums[j];
                long long length = j - i + 1;
                long long score = sum * length;

                if(score < k){
                    count++;
                }
            }
        }
        return count;
    }
};



// Sliding Window
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        
        long long result = 0;
        long long sum = 0;

        int i=0, j=0;

        while(j<n){
            sum += nums[j];

            while(i <= j && sum * (j-i+1) >= k){
                sum -= nums[i];
                i++;
            }

            // going through more elements----> (i+1) then (i+2)........

            result += (j-i+1);
            j++;
        }

        return result;
    }
};