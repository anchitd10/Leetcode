// Problem-3228: Maximum number of operations to move ones to end

// You are given a binary string s.
// You can perform the following operation on the string any number of times:
// Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
// Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
// Return the maximum number of operations that you can perform.
// Example :
// Input: s = "1001101"
// Output: 4
// Explanation:
// We can perform the following operations:
// Choose index i = 0. The resulting string is s = "0011101".
// Choose index i = 4. The resulting string is s = "0011011".
// Choose index i = 3. The resulting string is s = "0010111".
// Choose index i = 2. The resulting string is s = "0001111".

class Solution {
public:
    int maxOperations(string s) {
        reverse(s.begin(), s.end());

        int n = s.length(), startIndex = n;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                startIndex = i;
                break;
            }
        }

        int impact = 1, ans = 0, j = -1;
        for (int i = startIndex; i < n; i++) {
            if (s[i] == '0')
                continue;
            int count = 0;
            for (j = i; j < n; j++) {
                if (s[j] == '0')
                    break;
                count++;
            }

            ans += count * impact;
            impact++;
            i = j - 1;
        }
        return ans;
    }
};
