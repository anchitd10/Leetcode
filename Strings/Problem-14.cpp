// Problem-14: Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        int n = strs.size();
        string ans="";

        int minLength = strs[0].size();
        for (const string& str : strs) {
            minLength = min(minLength, (int)str.size());
        }

        for(int i=0; i<minLength; i++){
            char ch = strs[0][i];

            bool match = true;

            for(int j=1; j<n; j++){
                // jth character should correspond to the position of ith character in first string
                if(strs[j].size() < i || ch != strs[j][i]){
                    match = false;
                    break;
                }
            }

            if(match == false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};