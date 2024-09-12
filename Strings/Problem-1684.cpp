// Problem-1684: Count the Number of Consistent Strings

// You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
// Return the number of consistent strings in the array words.
// Example 1:
// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
// Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        bool alphabet[26] = {};

        for(char c : allowed) alphabet[c-'a'] = true;

        for(string word : words){
            for(char c : word){
                if(!alphabet[c-'a']){
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};