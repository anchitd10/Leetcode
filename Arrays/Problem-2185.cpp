// Problem-2185: Counting Words With a Given Prefix

// You are given an array of strings words and a string pref.
// Return the number of strings in words that contain pref as a prefix.
// A prefix of a string s is any leading contiguous substring of s.
// Example 1:
// Input: words = ["pay","attention","practice","attend"], pref = "at"
// Output: 2
// Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int n = words.size();
        
        for(int i=0; i<n; i++){
            if(words[i].find(pref) == 0){
                count++;
            }
        }
        return count;
    }
};