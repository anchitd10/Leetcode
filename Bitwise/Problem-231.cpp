// Problem-231: Power of Two

// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.
// Example:
// Example 1:
// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:
// Input: n = 16
// Output: true
// Explanation: 24 = 16


// Concept: Bitwise Operations
// Approach: Use bitwise AND operation to check if n is a power of two. A number is a power of two if it has exactly one bit set in its binary representation.
// SO AND operation between n and (n - 1) should be zero if n is a power of two, and n should be greater than zero.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};