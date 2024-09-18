// Problem-326: Power of Three

// Given an integer n, return true if it is a power of three. Otherwise, return false.
// An integer n is a power of three, if there exists an integer x such that n == 3x.
// Example 1:
// Input: n = 27
// Output: true
// Explanation: 27 = 33

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};


//recursion
bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;

    if (n % 3 != 0) return false;

    return isPowerOfThree(n / 3);
}