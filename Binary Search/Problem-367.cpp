// Problem-367: Valid Perfect Square

// Given a positive integer num, return true if num is a perfect square or false otherwise.
// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
// You must not use any built-in library function, such as sqrt.
// Example 1:
// Input: num = 16
// Output: true
// Explanation: We return true because 4 * 4 = 16 and 4 is an integer.


class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;

        while(left <= right){
            long long mid = left + (right-left)/2;
            long long square = mid * mid;

            if(square == num){
                return true;
            }

            if(square > num){
                right = mid - 1;
            }
            else if(square < num){
                left = mid + 1;
            }
        }

        return false;
    }
};