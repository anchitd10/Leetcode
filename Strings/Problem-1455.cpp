// Problem-1455: Check If A Word Occurs As a Prefix of Any Word in a Sentence

// Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.
// Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.
// A prefix of a string s is any leading contiguous substring of s.
// Example 1:
// Input: sentence = "i love eating burger", searchWord = "burg"
// Output: 4
// Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1;
        int n = sentence.size();
        int searchLen = searchWord.size();

        for (int i = 0; i < n; i++) {
            if (sentence.compare(i, searchLen, searchWord) == 0) {
                return wordIndex;
            }

            while (i < n && sentence[i] != ' ') {
                i++;
            }
            wordIndex++;
        }

        return -1;
    }
};