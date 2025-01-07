// Problem-1408: String Matching in an Array

// Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
// A substring is a contiguous sequence of characters within a string
// Example 1:
// Input: words = ["mass","as","hero","superhero"]
// Output: ["as","hero"]
// Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
// ["hero","as"] is also a valid answer.


// brute force
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j){
                    continue;
                }

                if(words[j].find(words[i]) != string::npos){
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};


// KMP string matching algo

class Solution {
public:
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0;

        lps[0] = 0; // no proper suffix or prefix for the first character

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool searchKMP(string pat, string text) {
        int N = text.length();
        int M = pat.length();

        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0, j = 0;
        while (i < N) {
            if (pat[j] == text[i]) {
                i++;
                j++;
            }
            if (j == M) {
                return true; // found a match
            } else if (i < N && pat[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && searchKMP(words[i], words[j])) {
                    result.push_back(words[i]);
                    break; // move to the next word
                }
            }
        }
        return result;
    }
};