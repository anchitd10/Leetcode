// Problem-1963: Minimum Number of Swaps to Make String Balanced

// You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.
// A string is called balanced if and only if:
// It is the empty string, or
// It can be written as AB, where both A and B are balanced strings, or
// It can be written as [C], where C is a balanced string.
// You may swap the brackets at any two indices any number of times.
// Return the minimum number of swaps to make s balanced.
// Input: s = "][]["
// Output: 1
// Explanation: You can make the string balanced by swapping index 0 with index 3.
// The resulting string is "[[]]".

class Solution {
public:
    int minSwaps(string s) {
        stack<char> myStack;

        for(char ch : s){
            if(ch == '['){
                myStack.push(ch);
            }
            else if(!myStack.empty()){
                myStack.pop();
            }
        }
        return (myStack.size()+1)/2;
    }
};

//without stack
class Solution {
public:
    int minSwaps(string s) {
        int size = 0;

        for(char ch : s){
            if(ch == '['){
                size++;
            }
            else if(size > 0){
                size--;
            }
        }
        return (size + 1)/2;
    }
};