// Problem-3085: Minimum Deletions to Make String K-Special

// You are given a string word and an integer k.
// We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
// Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.
// Return the minimum number of characters you need to delete to make word k-special.
// Example 1:
// Input: word = "aabcaba", k = 0
// Output: 3
// Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1 occurrence of "c". Therefore, word becomes equal to "baba" where freq('a') == freq('b') == 2.



class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for (char& ch : word) {
            freq[ch - 'a']++;
        }

        int result = word.length();

        for (int i = 0; i < 26; i++) {

            int del = 0;

            for (int j = 0; j < 26; j++) {
                if (i == j)
                    continue;

                if (freq[j] < freq[i]) {
                    del += freq[j];
                } else if (abs(freq[j] - freq[i]) > k) {
                    del += abs(freq[j] - freq[i] - k);
                }
            }

            result = min(result, del);
        }
        return result;
    }
};


//  Approach-2
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for (char& ch : word) {
            freq[ch - 'a']++;
        }

        sort(begin(freq), end(freq));

        int result = word.length();
        int cumulative_del = 0;

        for (int i = 0; i < 26; i++) {

            int del = cumulative_del;

            for (int j = 25; j > i; j--) {
                if(freq[j] - freq[i] <= k){
                    break;
                }

                del += freq[j] - freq[i] - k;
            }

            result = min(result, del);
            cumulative_del += freq[i];
        }
        return result;
    }
};