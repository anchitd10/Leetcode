// Problem-69: Sqrt(x)

// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
// You must not use any built-in exponent function or operator.
// - For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
// Example 1:
// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        while(low <= high){
            long long mid = low + (high - low)/2;        // to avoid overflow
            long long val = mid * mid;

            if(val > x){
                high = mid - 1;
            }
            else if(val <= x){
                low = mid + 1;
            }
        }
        return high;
    }
};