// Problem-6: Zigzag Conversion

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string s, int numRows);
// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"


// Concept: Just calculate the number of steps to reach next char in the same row for top and bottom most then check for the middle rows and add accordingly

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();

        if(numRows == 1){
            return s;
        }

        string res = "";

        for(int r=0; r < numRows; r++){
            int increment = 2*(numRows-1);

            for(int i=r; i<n; i+=increment){
                res += s[i];

                if(r>0 && r<numRows-1 && (i + increment - 2 * r) < n){
                    res += s[i + increment - 2 * r];
                }
            }
        }

        return res;
    }
};