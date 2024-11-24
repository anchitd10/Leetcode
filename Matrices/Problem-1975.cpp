// Problem-1975: Maximum Matrix Sum

// You are given an n x n integer matrix. You can do the following operation any number of times:
// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.
// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
// Example:
// Input: matrix = [[1,-1],[-1,1]]

// [[1,-1]
//  [-1,1]]

// Output: 4
// Explanation: We can follow the following steps to reach sum equals 4:
// - Multiply the 2 elements in the first row by -1.
// - Multiply the 2 elements in the first column by -1.

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        long long result = 0;
        int minNum = INT_MAX;
        int negativeCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                minNum = min(minNum, abs(matrix[i][j]));
                if (matrix[i][j] < 0) {
                    negativeCount++;
                }
                result += abs(matrix[i][j]);
            }
        }

        //subtract twice of smallest value if negative count is odd.....first to remove the value of number from total sum and the second time for the negative value
        if (negativeCount % 2 != 0) {
            result -= 2 * minNum;
        }

        return result; // Ensure the function returns the computed result
    }
};