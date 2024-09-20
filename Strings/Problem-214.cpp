// Problem-214: Shortest Palindrome

// You are given a string s. You can convert s to a 
// palindrome by adding characters in front of it.
// Return the shortest palindrome you can find by performing this transformation.
// Example 1:
// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:
// Input: s = "abcd"
// Output: "dcbabcd"

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (j >= 0) {
            if (s[i] == s[j]) {
                i++;
            }
            j--;
        }
        if (i == n) {
            return s;
        }
        string suffix = s.substr(i);
        reverse(suffix.begin(), suffix.end());
        return suffix + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};
 

