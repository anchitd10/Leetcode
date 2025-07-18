// Problem-3442: Maximum Difference Between Even and Odd Frequency I

// You are given a string s consisting of lowercase English letters.
// Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
// - a1 has an odd frequency in the string.
// - a2 has an even frequency in the string.
// Return this maximum difference. 
// Example 1:
// Input: s = "aaaaabbc"
// Output: 3
// Explanation:
// The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
// The maximum difference is 5 - 2 = 3.


class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();

        int maxChar = 0;
        int minChar = INT_MAX;

        vector<int> freq(26,0);

        for(char &ch : s){
            freq[ch - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;

            if(freq[i]%2 == 0){
                minChar = min(minChar, freq[i]);
            }

            if(freq[i]%2 != 0){
                maxChar = max(maxChar, freq[i]);
            }
        }

        return maxChar - minChar;
    }
};