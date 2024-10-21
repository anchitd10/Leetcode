// Problem-1593: Split a String into the Max Number of Unique Substrings

// Given a string s, return the maximum number of unique substrings that the given string can be split into.
// You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
// A substring is a contiguous sequence of characters within a string.
// Example 1:
// Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.

class Solution {
public:
    void solve(string& s, int i, unordered_set<string>& st, int currCount, int& maxCount){
        if(currCount + (s.length()-i) <= maxCount){
            return;
        }

        if(i >= s.length()){
            maxCount = max(maxCount, currCount);
            return;
        }
        
        for(int j=i; j<s.length(); j++){
            string sub = s.substr(i, j-i+1);
            if(st.find(sub) == st.end()){
                st.insert(sub);
                solve(s, j+1, st, currCount+1, maxCount);
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount = 0;
        int currCount = 0;
        int i = 0;
        solve(s, i, st, currCount, maxCount);

        return maxCount;
    }
};