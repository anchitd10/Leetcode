// Problem-1653: Minimum deletions to make string balanced

// You are given a string s consisting only of characters 'a' and 'b'​​​​.
// You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
// Return the minimum number of deletions needed to make s balanced.
// Example 1:
// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

class Solution {
public:
    int minimumDeletions(string s) {
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='b'){
            b++;
           }
           else if(s[i]=='a' && b>a){
            a++;
           }
        }
        return a;
    }
};