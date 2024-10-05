// Problem-567: Permutation in String

// Given two strings s1 and s2, return true if s2 contains a 
// permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.
// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        if (m > n) return false;
        
        vector<int> s1Freq(26, 0), windowFreq(26, 0);
        
        //frequency of each character in s1
        for (char c : s1) {
            s1Freq[c - 'a']++;
        }
        
        //sliding window
        for (int i = 0; i < n; i++) {
            windowFreq[s2[i] - 'a']++;
            
            if (i >= m) {
                windowFreq[s2[i - m] - 'a']--;
            }
            
            if (s1Freq == windowFreq) {
                return true;
            }
        }
        
        return false;
    }
};
