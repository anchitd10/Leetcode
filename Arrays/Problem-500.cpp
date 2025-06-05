// Problem-500: Keyboard Row

// Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
// In the American keyboard:
// - the first row consists of the characters "qwertyuiop",
// - the second row consists of the characters "asdfghjkl", and
// - the third row consists of the characters "zxcvbnm".
// Example 1:
// Input: words = ["Hello","Alaska","Dad","Peace"]
// Output: ["Alaska","Dad"]
// Explanation:
// Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.


class Solution {
public:
    bool check(char c, string s){
        for(auto i : s){
            if(i == c){
                return true;
            }
        }
        return false;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> mp = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> ans;
        int n = words.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                bool found = true;

                for(int k=0; k<words[i].size(); k++){
                    if(!check(tolower(words[i][k]), mp[j])) {
                        found = false;
                    }
                }

                if(found){
                        ans.push_back(words[i]);
                        break;
                    }
            }
        }
        return ans;
    }
};