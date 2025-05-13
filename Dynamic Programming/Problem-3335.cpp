// Problem-3335: Total Characters in String After Transformations I

// You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
// - If the character is 'z', replace it with the string "ab".
// - Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
// Return the length of the resulting string after exactly t transformations.
// Since the answer may be very large, return it modulo 109 + 7.
// Example 1:
// Input: s = "abcyy", t = 2
// Output: 7
// Explanation:
// First Transformation (t = 1):
// 'a' becomes 'b'
// 'b' becomes 'c'
// 'c' becomes 'd'
// 'y' becomes 'z'
// 'y' becomes 'z'
// String after the first transformation: "bcdzz"
// Second Transformation (t = 2):
// 'b' becomes 'c'
// 'c' becomes 'd'
// 'd' becomes 'e'
// 'z' becomes "ab"
// 'z' becomes "ab"
// String after the second transformation: "cdeabab"
// Final Length of the string: The string is "cdeabab", which has 7 characters.



class Solution {
public:
    int M = 1e9+7;

    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        // unordered_map<char, int> mp;
        vector<int> mp(26, 0);

        for (char& ch : s) {
            mp[ch - 'a']++;
        }

        for (int count = 1; count <= t; count++) { // O(t)
            // unordered_map<char, int> temp;
            vector<int> temp(26, 0);

            for (int i = 0; i < 26; i++) { // O(26)
                char ch = i + 'a';         // 0->a, 1->b and so on
                int freq = mp[i];

                if (ch != 'z') {
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % M;
                } else {
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
                }
            }

            mp = move(temp);
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result = (result + mp[i]) % M;
        }

        return result;
    }
};