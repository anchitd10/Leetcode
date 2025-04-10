// Problem-2999: Count the Number of Powerful Integers

// You are given three integers start, finish, and limit. You are also given a 0-indexed string s representing a positive integer.
// A positive integer x is called powerful if it ends with s (in other words, s is a suffix of x) and each digit in x is at most limit.
// Return the total number of powerful integers in the range [start..finish].
// A string x is a suffix of a string y if and only if x is a substring of y that starts from some index (including 0) in y and extends to the index y.length - 1. For example, 25 is a suffix of 5125 whereas 512 is not.
// Example 1:
// Input: start = 1, finish = 6000, limit = 4, s = "124"
// Output: 5
// Explanation: The powerful integers in the range [1..6000] are 124, 1124, 2124, 3124, and, 4124. All these integers have each digit <= 4, and "124" as a suffix. Note that 5124 is not a powerful integer because the first digit is 5 which is greater than 4.
// It can be shown that there are only 5 powerful integers in this range.


class Solution {
    public:
        using ll = long long;
    
        ll countValidNumbers(int idx, int tight, string &numStr, string &suffix, int limit, int numLength, vector<vector<ll>>& dp) {
            if (idx == numLength) return 1;
            if (dp[idx][tight] != -1) return dp[idx][tight];
    
            ll lowerBound = 0 , count = 0;
            int upperBound = tight ? min(limit, numStr[idx] - '0') : limit;
    
            int suffixStartIdx = numLength - suffix.size();
            if (suffixStartIdx <= idx) {
                lowerBound = suffix[idx - suffixStartIdx] - '0';
                upperBound = min(upperBound, suffix[idx - suffixStartIdx] - '0');
            }
    
            for (int i = lowerBound; i <= upperBound; i++) 
            count += countValidNumbers(idx + 1, tight && (i == numStr[idx] - '0'), numStr, suffix, limit, numLength, dp);
            
            return dp[idx][tight] = count;
        }
    
        ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
            string upperLimit = to_string(finish);
            string lowerLimit = to_string(start - 1);
            int upperLength = upperLimit.size() , lowerLength = lowerLimit.size();
    
            ll upperCount = 0, lowerCount = 0;
            vector<vector<ll>> dp(17, vector<ll>(2, -1));
    
            if (s.size() <= upperLength) 
                upperCount = countValidNumbers(0, 1, upperLimit, s, limit, upperLength, dp);
    
            dp.assign(17, vector<ll>(2, -1));
            if (s.size() <= lowerLength) 
                lowerCount = countValidNumbers(0, 1, lowerLimit, s, limit, lowerLength, dp);
    
            return upperCount - lowerCount;
        }
    };