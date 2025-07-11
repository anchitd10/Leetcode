// Problem-344: Reverse String

// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.
// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]


class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        int n = s.size();

        for(char &c : s){
            st.push(c);
        }

        for(int i=0; i<n; i++){
            s[i] = st.top();
            st.pop();
        }
    }
};