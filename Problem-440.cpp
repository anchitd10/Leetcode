// Problem-440: K-th Smallest in Lexicographical Order

// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
// Example 1:
// Input: n = 13, k = 2
// Output: 10
// Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.


class Solution {
public:
    // Function to count how many numbers are lexicographically between prefix and n
    int countSteps(int curr, long n) {
        long steps = 0;
        long first = curr;
        long last = curr;

        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int steps = countSteps(curr, n);
            
            if (steps <= k) {
                //if there are fewer than or equal to k numbers in this prefix
                //skip this prefix and go to the next number.
                curr++;
                k -= steps;
            } else {
                //elsego deeper in this prefix
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};
