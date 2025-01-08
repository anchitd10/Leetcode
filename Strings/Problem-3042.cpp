// Problem-3042: Count Prefix and Suffix Pairs I

// You are given a 0-indexed string array words.
// Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:
// isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
// For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
// Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.
// Example 1:
// Input: words = ["a","aba","ababa","aa"]
// Output: 4
// Explanation: In this example, the counted index pairs are:
// i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
// i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
// i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
// i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
// Therefore, the answer is 4.

// using substr()
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                string str1 = words[i];
                string str2 = words[j];
                int m = str1.length();

                if(str2.substr(0, m) == words[i] && str2.substr(str2.length() - m) == str1){
                    count++;
                }
            }
        }
        return count;
    }
};


// using find()
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string str1 = words[i];
                string str2 = words[j];

                if(str2.find(str1) == 0 && str2.rfind(str1) == str2.length() - str1.length()){
                    count++;
                }
            }
        }
        return count;
    }
};