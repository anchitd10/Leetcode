// Problem-3174: Clear Digits

// You are given a string s.
// Your task is to remove all digits by doing this operation repeatedly:
// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.
// Example 1:
// Input: s = "abc"
// Output: "abc"
// Explanation:
// There is no digit in the string.
// Example 2:
// Input: s = "cb34"
// Output: ""
// Explanation:
// First, we apply the operation on s[2], and s becomes "c4".
// Then we apply the operation on s[1], and s becomes "".

// Brute Force

class Solution
{
public:
    string clearDigits(string s)
    {
        int i = 0;

        while (i < s.length())
        {
            if (isdigit(s[i]))
            {
                s.erase(i, 1);
                if (i - 1 >= 0)
                {
                    s.erase(i - 1, 1);
                    i--;
                }
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};