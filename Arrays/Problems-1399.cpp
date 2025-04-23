// Problem-1399: Count Largest Group

// You are given an integer n.
// Each number from 1 to n is grouped according to the sum of its digits.
// Return the number of groups that have the largest size.
// Example 1:
// Input: n = 13
// Output: 4
// Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
// [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
// There are 4 groups with largest size.


class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> sums(37);
        for (int i = 1; i <= n; i++) sums[digsum(i)]++;

        int maxi = 0, count = 0;
        for (int i : sums) 
            if (i > maxi) maxi = i, count = 1;
            else if (i == maxi) ++count;
        
        return count;
    }
    int digsum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};