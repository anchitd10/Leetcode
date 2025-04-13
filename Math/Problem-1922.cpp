// Problem-1922: Count Good Numbers

// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
// Example 1:
// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

class Solution {
public:
    const int M = 1e9+7;
    int findPower(long long a, long long b){
        if(b == 0){
            return 1;
        }

        long long half = findPower(a, b/2);
        long long result = (half * half) % M;

        if(b % 2 == 1){
            result = (result * a) % M;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        // we are taking number of possibilities for even and odd places.....5 possibilities for even places and 4 form odd/prime
        return (long long)findPower(5, (n+1)/2) * findPower(4, n/2) % M;
    }
};