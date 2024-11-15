// Problem-383: Ransom Note

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.
// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(int i=0; i<magazine.length(); i++){
            m[magazine[i]]++;
        }

        for(int j=0; j<ransomNote.length(); j++){
            if(m[ransomNote[j]] >= 1){
                m[ransomNote[j]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};