// Problem-1910: Remove All Occurrences of a Substring

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string.
// Example 1:
// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (true) {
            int idx = s.find(part);

            if (idx == string::npos) {
                break;
            }

            s.erase(idx, part.length());
        }
        return s;
    }
};


// Stack
class Solution {
public:
    bool check(stack<char>& st, string& part, int n){
        stack<char> tempSt = st;

        for(int idx = n-1; idx >= 0; idx--){
            if(tempSt.top() != part[idx]){
                return false;
            }

            tempSt.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> st;

        int m = s.length();
        int n = part.length();

        for(int i=0; i<m; i++){
            st.push(s[i]);

            if(st.size() >= n && check(st, part, n) == true){
                for(int j=0; j<n; j++){
                    st.pop();
                }
            }
        }

        string result = "";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));

        return result;
    }
};