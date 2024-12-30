// Problem-2466: Count Ways To Build Good Strings

// Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
// - Append the character '0' zero times.
// - Append the character '1' one times.
// - This can be performed any number of times.
// A good string is a string constructed by the above process having a length between low and high (inclusive).
// Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.
// Example 1:
// Input: low = 3, high = 3, zero = 1, one = 1
// Output: 8
// Explanation: 
// One possible valid good string is "011". 
// It can be constructed as follows: "" -> "0" -> "01" -> "011". 
// All binary strings from "000" to "111" are good strings in this example.

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(high + 1, 0);
        
        dp[0] = 1;
        
        for (int i = 0; i < high; i++) {
            if (i + zero <= high) {
                dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
            }
            if (i + one <= high) {
                dp[i + one] = (dp[i + one] + dp[i]) % MOD;
            }
        }
        
        long long result = 0;
        for (int i = low; i <= high; i++) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};