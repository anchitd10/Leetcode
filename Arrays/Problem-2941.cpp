// Problem-2942: Find Words Containing Characters

// You are given a 0-indexed array of strings words and a character x.
// Return an array of indices representing the words that contain the character x.
// Note that the returned array may be in any order.
// Example 1:
// Input: words = ["leet","code"], x = "e"
// Output: [0,1]
// Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> indices;

        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                if (c == x) {
                    indices.push_back(i);
                    break;
                }
            }
        }
        return indices;
    }
};