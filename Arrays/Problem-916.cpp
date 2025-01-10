// Problem-916: Word Subsets

// You are given two string arrays words1 and words2.
// A string b is a subset of string a if every letter in b occurs in a including multiplicity.
// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.
// Return an array of all the universal strings in words1. You may return the answer in any order.
// Example 1:
// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]

class Solution {
public:
    bool isSubset(vector<int>& freq, vector<int>& temp){
        for(int i=0; i<26; i++){
            if(temp[i] < freq[i]){
                return false;
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;

        vector<int> freq(26);
        for(string &word : words2){
            vector<int> temp(26,0);

            for(char &ch : word){
                temp[ch - 'a']++;

                freq[ch - 'a'] = max(freq[ch - 'a'], temp[ch - 'a']);
            }
        }

        for(string &word : words1){
            vector<int> temp(26,0);

            for(char &ch : word){
                temp[ch - 'a']++;
            }

            if(isSubset(freq, temp) == true){
                result.push_back(word);
            }
        }
        return result;
    }
};