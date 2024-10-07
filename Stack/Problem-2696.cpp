// Problem-2696: Minimum String Length After Removing Substrings

// You are given a string s consisting only of uppercase English letters.
// You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.
// Return the minimum possible length of the resulting string that you can obtain.
// Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
// Example 1:
// Input: s = "ABFCACDB"
// Output: 2
// Explanation: We can do the following operations:
// - Remove the substring "ABFCACDB", so s = "FCACDB".
// - Remove the substring "FCACDB", so s = "FCAB".
// - Remove the substring "FCAB", so s = "FC".
// So the resulting length of the string is 2.

class Solution {
public:
    int minLength(string s) {
        stack<char> myStack;

        for(char ch : s){
            if(!myStack.empty() && ((ch == 'B' && myStack.top() == 'A') || (ch == 'D' && myStack.top() == 'C'))) {
                myStack.pop();
            } else {
                myStack.push(ch);
            }
        }
        return myStack.size();
    }
};