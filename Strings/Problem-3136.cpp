// Problem-3136: Valid Word

// A word is considered valid if:
// It contains a minimum of 3 characters.
// It contains only digits (0-9), and English letters (uppercase and lowercase).
// It includes at least one vowel.
// It includes at least one consonant.
// You are given a string word.
// Return true if word is valid, otherwise, return false.
// Notes:
// 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
// A consonant is an English letter that is not a vowel.
// Example 1:
// Input: word = "234Adas"
// Output: true
// Explanation:
// This word satisfies the conditions.



class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3){
            return false;
        }

        bool hasVowel = false;
        bool hasConsonant = false;

        for(char ch : word){
            if(isalpha(ch)){
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    hasVowel = true;
                }
                else{
                    hasConsonant = true;
                }
            }
            else if(!isdigit(ch)){
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
};