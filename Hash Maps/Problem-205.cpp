// Problem-205: Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false
// Explanation:
// The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> first, second;

        for(int i=0; i<s.length(); i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(first.find(ch1) != first.end() && first[ch1] != ch2 || second.find(ch2) != second.end() && second[ch2] != ch1){
                return false;
            }
            first[ch1] = ch2;
            second[ch2] = ch1;
        }
        return true;
    }
};