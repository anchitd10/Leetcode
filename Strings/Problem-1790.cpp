// Problem-1790: Check if One String Swap Can Make Strings Equal

// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
// Example 1:
// Input: s1 = "bank", s2 = "kanb"
// Output: true
// Explanation: For example, swap the first character with the last character of s2 to make "bank".

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }

        int n = s1.length();
        int diffs = 0;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                diffs++;
            }

            if(diffs > 2){
                return false;
            }

            // to check if both strings have same characters
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};