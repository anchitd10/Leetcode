// Problem-1002: Find Common Characters

// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// Example 1:
// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> charCount(26, 0);
        vector<int> tempCount(26, 0);

        for (char c : words[0]) {
            charCount[c - 'a']++;
        }

        // keep only the minimum frequency.
        for (int i = 1; i < words.size(); i++) {
            fill(tempCount.begin(), tempCount.end(), 0); // Reset tempCount
            for (char c : words[i]) {
                tempCount[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                charCount[j] = min(charCount[j], tempCount[j]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (charCount[i] > 0) {
                result.push_back(string(1, i + 'a')); // add character as many times as its frequency.
                charCount[i]--;
            }
        }
        return result;
    }
};