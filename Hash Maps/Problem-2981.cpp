// Problem-2981: Find Longest Special Substring That Occurs Thrice I

// You are given a string s that consists of lowercase English letters.
// A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.
// Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.
// A substring is a contiguous non-empty sequence of characters within a string.
// Example 1:
// Input: s = "abcaba"
// Output: 1
// Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
// It can be shown that the maximum length achievable is 1.

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> substringCount;
        int maxLength = -1;

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                string substr = s.substr(i, len);

                if (isSpecial(substr)) {
                    substringCount[substr]++;
                    if (substringCount[substr] >= 3) {
                        maxLength = max(maxLength, len);
                    }
                }
            }
        }

        return maxLength;
    }

    bool isSpecial(const string &str) {
        char firstChar = str[0];
        for (char c : str) {
            if (c != firstChar) {
                return false;
            }
        }
        return true;
    }
};