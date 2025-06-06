// Problem-2434: Using a Robot to Print the Lexicographically Smallest String

// You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
// - Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
// - Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
// Return the lexicographically smallest string that can be written on the paper.
// Example 1:
// Input: s = "zza"
// Output: "azz"
// Explanation: Let p denote the written string.
// Initially p="", s="zza", t="".
// Perform first operation three times p="", s="", t="zza".
// Perform second operation three times p="azz", s="", t="".


class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> minCharToRight(n);

        minCharToRight[n-1] = s[n-1];
        for(int i=n-2; i>=0; i--){
            minCharToRight[i] = min(s[i], minCharToRight[i+1]);
        }

        string t = "";
        string paper = "";

        int i = 0;
        while(i < n){
            t.push_back(s[i]);

            char minChar = (i+1 < n) ? minCharToRight[i+1] : s[i];

            while(!t.empty() && t.back() <= minChar){
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        while(!t.empty()){
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};