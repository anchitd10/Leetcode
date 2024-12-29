// Problem-1639: Number of Ways to Form a Target String Given a Dictionary

// You are given a list of strings of the same length words and a string target.
// Your task is to form target using the given words under the following rules:
// - target should be formed from left to right.
// - To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
// - Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
// - Repeat the process until you form the string target.
// Notice that you can use multiple characters from the same string in words provided the conditions above are met.
// Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

// Example 1:
// Input: words = ["acca","bbbb","caca"], target = "aba"
// Output: 6
// Explanation: There are 6 ways to form target.
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();
        
        // character frequencies at each position
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[j][word[j] - 'a']++;
            }
        }
        
        // dp
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                // skip the current column
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                
                // use current column if possible
                if (j < m) {
                    char targetChar = target[j];
                    int charCount = freq[i][targetChar - 'a'];
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * charCount) % MOD;
                }
            }
        }
        
        return dp[n][m];
    }
};