// Problem-1323: Maximum 69 Number

// You are given a positive integer num consisting only of digits 6 and 9.
// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
// Example 1:
// Input: num = 9669
// Output: 9969
// Explanation: 
// Changing the first digit results in 6669.
// Changing the second digit results in 9969.
// Changing the third digit results in 9699.
// Changing the fourth digit results in 9666.
// The maximum number is 9969.


// Concept: Iterate from the end by taking rem and get the highest index of 6 digit and add 3 to it to change it to 9.

class Solution {
public:
    int maximum69Number (int num) {
        int counter = 0;
        int sixIndex = -1;
        int temp = num;

        while(temp > 0){
            int rem = temp % 10;

            if(rem == 6){
                sixIndex = counter;
            }

            temp /= 10;
            counter++;
        }

        if(sixIndex == -1){
            return num;
        }

        return num + (3 * pow(10, sixIndex));
    }
};