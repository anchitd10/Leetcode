// Problem-796: Rotate Strings

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
// Example 1:
// Input: s = "abcde", goal = "cdeab"
// Output: true

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n){
            return false;
        }
        
        for(int count=1; count <=m; count++){
            rotate(begin(s), begin(s)+1, end(s));
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};