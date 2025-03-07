// Problem-2523: Closest Prime Numbers in Range

// Given two positive integers left and right, find the two integers num1 and num2 such that:
// - left <= num1 < num2 <= right .
// - Both num1 and num2 are prime numbers.
// - num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
// Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
// Example 1:
// Input: left = 10, right = 19
// Output: [11,13]
// Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
// The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
// Since 11 is smaller than 17, we return the first pair.


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
         if (left > right) return {-1, -1};

        // Sieve of Eratosthenes
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // collect primes in the range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) primes.push_back(i);
        }

        // if fewer than 2 primes exist, return [-1, -1]
        if (primes.size() < 2) return {-1, -1};

        // find the closest prime pair
        int minDiff = INT_MAX, num1 = -1, num2 = -1;
        for (size_t i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                num1 = primes[i - 1];
                num2 = primes[i];
            }
        }

        return {num1, num2};
    }
};