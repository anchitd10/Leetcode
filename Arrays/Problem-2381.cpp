// Problem-2381: Shifting Letters II

// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
// Return the final string after all such shifts to s are applied.
// Example 1:
// Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
// Output: "ace"
// Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
// Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
// Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0); // difference array

        // shifts to the difference array
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            int shiftAmount = direction == 1 ? 1 : -1;
            diff[start] += shiftAmount;
            diff[end + 1] -= shiftAmount;
        }

        // accumulate the differences to get the net shift for each character
        int shiftSum = 0;
        for (int i = 0; i < n; ++i) {
            shiftSum += diff[i];
            int newPos = (s[i] - 'a' + shiftSum) % 26;
            if (newPos < 0) {
                newPos += 26;
            }
            s[i] = 'a' + newPos;
        }

        return s;
    }
};