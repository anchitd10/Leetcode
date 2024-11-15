// Problem-242: Valid Anagram

// Given two strings s and t, return true if t is an 
// anagram of s, and false otherwise.
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:
// Input: s = "rat", t = "car"
// Output: false

class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(begin(s), end(s));
        // sort(begin(s), end(t));
        // if(s == t){
        //     return true;
        // }
        
        vector<int> count(26,0);

        for(char &ch : s){
            count[ch-'a']++;
        }

        for(char &ch : t){
            count[ch-'a']--;
        }

        bool allZeros = all_of(begin(count), end(count), [](int element){
            return element == 0;
        });
        return allZeros;
    }
};