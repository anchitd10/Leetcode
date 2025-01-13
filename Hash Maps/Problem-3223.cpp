// Problem-3223: Minimum Length of String After Operations

// You are given a string s.
// You can perform the following process on s any number of times:
// - Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
// - Delete the closest character to the left of index i that is equal to s[i].
// - Delete the closest character to the right of index i that is equal to s[i].
// Return the minimum length of the final string s that you can achieve.
// Example 1:
// Input: s = "abaacbcbb"
// Output: 5
// Explanation:
// We do the following operations:
// Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
// Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> freq(26,0);

        for(int i=0; i<n; i++){
            freq[s[i] - 'a'] += 1;

            if(freq[s[i] - 'a'] == 3){
                freq[s[i] - 'a'] -= 2;
            }
        }

        int result = 0;
        for(int i=0; i<26; i++){
            if(freq[i] == 0){
                continue;
            }

            result += freq[i];
        }
        return result;
    }
};