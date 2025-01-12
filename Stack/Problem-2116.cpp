// Problem-2116: Check if a Parentheses String Can Be Valid

// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
// - It is ().
// - It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// - It can be written as (A), where A is a valid parentheses string.
// You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
// If locked[i] is '1', you cannot change s[i].
// But if locked[i] is '0', you can change s[i] to either '(' or ')'.
// Return true if you can make s a valid parentheses string. Otherwise, return false.

class Solution {
public:
    bool canBeValid(string parentheses, string lockedStatus) {  //bool canbeValid(string s, string locked)
        int stringLength = parentheses.size();
        if (stringLength % 2 == 1) {
            return false;
        }

        stack<int> openIndices;
        stack<int> unlockedIndices;

        for (int i = 0; i < stringLength; i++) {
            if (lockedStatus[i] == '0') {
                unlockedIndices.push(i);
            } else if (parentheses[i] == '(') {
                openIndices.push(i);
            } else if (parentheses[i] == ')') {
                if (!openIndices.empty()) {
                    openIndices.pop();
                } else if (!unlockedIndices.empty()) {
                    unlockedIndices.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openIndices.empty() && !unlockedIndices.empty() &&
               openIndices.top() < unlockedIndices.top()) {
            openIndices.pop();
            unlockedIndices.pop();
        }

        if (openIndices.empty() && !unlockedIndices.empty()) {
            return unlockedIndices.size() % 2 == 0;
        }
        return openIndices.empty();
    }
};