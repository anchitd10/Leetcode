// Problem-290: Word Pattern

// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.
// Example 1:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Explanation:
// The bijection can be established as:
// 'a' maps to "dog".
// 'b' maps to "cat".

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);

        string token;
        int countWords = 0;

        while(getline(ss, token, ' ')){
            words.push_back(token);
            countWords++;
        }

        int n = pattern.length();
        if(n != countWords){
            return false;
        }

        unordered_map<string, char> mp;
        set<char> used;

        for(int i=0; i<n; i++){
            string word = words[i];
            char ch = pattern[i];

            if(mp.find(word) == mp.end() && used.find(ch) == used.end()){
                used.insert(ch);
                mp[word] = ch;
            }
            else if(mp[word] != pattern[i]){
                return false;
            }
        }
        return true;
    }
};