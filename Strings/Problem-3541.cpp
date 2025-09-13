// Problem-3541: Find Most Frequent Vowel and Consonant

// You are given a string s consisting of lowercase English letters ('a' to 'z').
// Your task is to:
// - Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
// - Find the consonant (all other letters excluding vowels) with the maximum frequency.
// Return the sum of the two frequencies.
// Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.
// The frequency of a letter x is the number of times it occurs in the string.
// Example 1:
// Input: s = "successes"
// Output: 6
// Explanation:
// The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
// The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
// The output is 2 + 4 = 6.

// Concept: Use a character frequency array to count the frequency of each character. Then, iterate through the array to find the maximum frequency of vowels and consonants.


class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        int maxVowel = 0;
        int maxConsonant = 0;

        for(char &c : s){
            int i = c-'a';
            freq[i]++;

            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                maxVowel = max(maxVowel, freq[i]);
            }
            else{
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }

        return maxVowel + maxConsonant;
    }
};