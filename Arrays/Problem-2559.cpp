// Problem-2559: Count Vowel Strings in Ranges

// You are given a 0-indexed array of strings words and a 2D array of integers queries.
// Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
// Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
// Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
// Example 1:
// Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
// Output: [2,3,0]
// Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
// The answer to the query [0,2] is 2 (strings "aba" and "ece").
// to query [1,4] is 3 (strings "ece", "aa", "e").
// to query [1,1] is 0.
// We return [2,3,0].

class Solution {
public:
    bool isVowel(char& ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int N = words.size();
        int Q = queries.size();
        int sum = 0;

        vector<int> result(Q);
        vector<int> cumSum(N);

        for (int i = 0; i < N ; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                sum++;
            }
            cumSum[i] = sum;
        }

        for (int i = 0; i < Q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            result[i] = cumSum[r] - ((l >0) ? cumSum[l-1] : 0);
        }
        return result;
    }
};