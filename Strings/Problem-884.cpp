// Problem-884: Uncommon Words from two Strings

// A sentence is a string of single-space separated words where each word consists only of lowercase letters.
// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
// Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        stringstream iss(s1 + " " + s2);

        while(iss >> s1) count[s1]++;

        vector<string> result;
        for(auto word : count){
            if(word.second == 1){
                result.push_back(word.first);
            }
        }
        return result;
    }
};