// Problem-2843: Count Symmetric Integers

// You are given two positive integers low and high.
// An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
// Return the number of symmetric integers in the range [low, high].
// Example 1:
// Input: low = 1, high = 100
// Output: 9
// Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
// Example 2:
// Input: low = 1200, high = 1230
// Output: 4
// Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.


// Approach-1
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int num = low; num <= high; num++){
            string s = to_string(num);

            int l = s.length();

            if(l%2 != 0){
                continue;
            }

            int leftSum = 0;
            int rightSum = 0;

            for(int i=0; i< l/2; i++){
                leftSum += s[i] - '0';
            }

            for(int i=l/2; i<l; i++){
                rightSum += s[i] - '0';
            }

            if(leftSum == rightSum){
                count++;
            }
        }
        return count;
    }
};


// Approach-2
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int num = low; num <= high; num++){
            if(num >= 10 && num <= 99 && num % 11 == 0){
                count++;
            }
            else if(num >= 1000 && num <= 9999){
                int first = num/1000;
                int second = (num/100) % 10;

                int third = (num/10) % 10;
                int fourth = num % 10;

                if(first + second == third + fourth){
                    count++;
                }
            }
        }
        return count;
    }
};