// Problem-3403: Find the Lexicographically Largest String From the Box I

// You are given a string word, and an integer numFriends.
// Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
// word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
// All the split words are put into a box.
// Find the lexicographically largest string from the box after all the rounds are finished.
// Example 1:
// Input: word = "dbca", numFriends = 2
// Output: "dbc"
// Explanation: 
// All possible splits are:
// - "d" and "bca".
// - "db" and "ca".
// - "dbc" and "a".

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        string result;
        int longestPossible = n - (numFriends - 1);

        if(numFriends == 1){
            return word;
        }

        for(int i=0; i<n; i++){
            int canTakeLength = min(longestPossible, n-i);

            result = max(result, word.substr(i, canTakeLength));
        }

        return result;
    }
};