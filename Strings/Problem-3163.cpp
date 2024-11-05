// Problem-3163: String Compression III

// Given a string word, compress it using the following algorithm:
// Begin with an empty string comp. While word is not empty, use the following operation:
// Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
// Append the length of the prefix followed by c to comp.
// Return the string comp.
// Example:
// Input: word = "aaaaaaaaaaaaaabb"
// Output: "9a5a2b"
// Explanation:
// Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.
// For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
// For prefix "aaaaa", append "5" followed by "a" to comp.
// For prefix "bb", append "2" followed by "b" to comp.

class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        string comp = "";
        int i=0;

        while(i<n){
            int count = 0;
            char c = word[i];

            while(i<n && count<9 && word[i] == c){
                count++;
                i++;
            }
            comp += to_string(count) + c;
        }
        return comp;
    }
};