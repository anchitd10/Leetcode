// Problem-125: Valid Palindrome

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.
// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;

        while(left < right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};