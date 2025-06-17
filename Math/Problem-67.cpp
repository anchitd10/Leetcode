// Problem-67: Add Binary

// Given two binary strings a and b, return their sum as a binary string.
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"


class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;  // carry from the previous step

        // add digit from a if available
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }

        // add digit from b if available
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        // add the least significant bit of sum to result
        result = char((sum % 2) + '0') + result;

        // Update carry (it will be 1 if sum is 2 or 3)
        carry = sum / 2;
    }

    return result;
    }
};