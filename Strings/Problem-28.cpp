// Problem-28: Find the Index of First Occurence in a String

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        for(int i=0; i<=(m-n); i++){
            for(int j=0; j<n; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
                if(j == n-1){
                    return i;
                }
            }
        }
        return -1;
    }
};