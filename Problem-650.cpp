// Problem-650: 2 Keys Keyboard

// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:
// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.
// Example 1:
// Input: n = 3
// Output: 3
// Explanation: Initially, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.

//recursion
class Solution {
public:
    int solve(int currA, int clipA, int n){
        if(currA == n){
            return 0;
        }

        if(currA > n){
            return 100000;
        }

        int copyAllPaste = 1 + 1 + solve(currA + currA, currA, n);  //1 for copy and then 1 for paste
        int paste = 1 + solve(currA + clipA, clipA, n);

        return min(copyAllPaste, paste);
    }

    int minSteps(int n) {
        if(n == 1){
            return 0;
        }

        return 1 + solve(1, 1, n);
    }
};