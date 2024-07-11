// Problem-1190: Reverse Substrings Between Each Pair of Parentheses

// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.
// Example:
// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.


// O(n^2) approach
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> mystack;
        for (auto c : s) {
            if (c == '(') {
                mystack.push(c);
            } else if (c == ')') {
                string temp = "";
                while (mystack.top() != '(') {
                    temp += mystack.top();
                    mystack.pop();
                }
                mystack.pop(); // to delete opening paranthesis

                for (auto ch : temp) {
                    mystack.push(ch);
                }
            } else {
                mystack.push(c); //push characters
            }
        }

        string ans = "";
        while (!mystack.empty()) {
            ans += mystack.top();
            mystack.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// wormhole teleportation
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> oppIndex(n, -1);
        stack<int> open;

        for (int i = 0; i < n; i++) {
            if (s[i] == '('){
                open.push(i);
            }
            else if (s[i] == ')') {
                int openIndex = open.top();
                open.pop();
                oppIndex[openIndex] = i;
                oppIndex[i] = openIndex;
            }
        }
        string ans = "";
        int dir = 1;
        for (int i = 0; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = oppIndex[i];
                dir *= -1;
            } 
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};