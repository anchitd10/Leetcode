// Problem-191: Number of 1 Bits

// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
// Example 1:
// Input: n = 11
// Output: 3
// Explanation:
// The input binary string 1011 has a total of three set bits.


// Approach 1:
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0){
            n = n & (n-1);
            count++;
        }

        return count;
    }
};


// Approach 2:
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0){
            count += (n % 2);
            n /= 2;
        }

        return count;
    }
};