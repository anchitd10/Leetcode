// Problem-592: Fraction Addition and Subtraction

// Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
// The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.
// Example:
// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"

class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;   // Numerator of the resultant fraction
        int denom = 1; // Denominator of the resultant fraction
        int i = 0;
        int n = expression.length();

        while (i < n) {
            int currNum = 0;
            int currDenom = 0;
            int sign = 1;  // Default sign is positive

            // Check for sign
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }

            // Build currNum
            while (i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';   // Get value of current numerator
                currNum = (currNum * 10) + val;
                i++;
            }
            currNum *= sign;  // Apply the sign to the numerator

            i++;  // Skip the '/'

            // Build currDenom
            while (i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';   // Get value of current denominator
                currDenom = (currDenom * 10) + val;
                i++;
            }

            // Add or subtract fractions: num/denom + currNum/currDenom
            num = num * currDenom + currNum * denom;
            denom *= currDenom;
        }

        // Simplify the fraction
        int GCD = abs(__gcd(num, denom));  // Calculate the greatest common divisor
        num /= GCD;
        denom /= GCD;

        return to_string(num) + '/' + to_string(denom);
    }
};
