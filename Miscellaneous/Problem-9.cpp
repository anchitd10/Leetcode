// Problem-9: Palindrome Number

// Given an integer x, return true if x is a 
// palindrome, and false otherwise.
// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        long reverse = 0;
        int temp = x;
        int digit = 0;
        while(x!=0){
            digit = x%10;
            reverse = reverse*10 + digit;
            x = x/10;
        }
        if(reverse == temp){
            return true;
        }
        else return false;
    }
};