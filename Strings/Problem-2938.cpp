// Problem-2938: Separate Black and White Balls

// There are n balls on a table, each ball has a color black or white.
// You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.
// In each step, you can choose two adjacent balls and swap them.
// Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.
// Example 1:
// Input: s = "101"
// Output: 1
// Explanation: We can group all the black balls to the right in the following way:
// - Swap s[0] and s[1], s = "011".
// Initially, 1s are not grouped together, requiring at least 1 step to group them to the right.

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long swap = 0;
        int black = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                swap += black;
            }
            else{
                black++;
            }
        }
        return swap;
    }
};