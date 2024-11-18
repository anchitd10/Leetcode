// Problem-1652: Defuse the Bomb

// You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.
// To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.
// If k > 0, replace the ith number with the sum of the next k numbers.
// If k < 0, replace the ith number with the sum of the previous k numbers.
// If k == 0, replace the ith number with 0.
// As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
// Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
// Example 1:
// Input: code = [5,7,1,4], k = 3
// Output: [12,10,16,13]
// Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> result(n, 0);
        if (k == 0) {
            return result;
        }

        int i = -1, j = -1;
        if (k > 0) {
            i = 1;
            j = k;
        } else {
            i = n - abs(k);
            j = n - 1;
        }

        int windowSum = 0;
        for (int pointer = i; pointer <= j; pointer++) {
            windowSum += code[pointer];
        }
        for (int k = 0; k < n; k++) {
            result[k] = windowSum;
            windowSum -= code[i % n];
            i++;

            windowSum += code[(j + 1) % n];
            j++;
        }
        return result;
    }
};