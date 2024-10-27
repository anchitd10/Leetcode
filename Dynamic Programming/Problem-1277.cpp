// Problem-1277: Count Square Submatrices with All Ones

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
// Example 1:
// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int result = 0;

        vector<vector<int>> t(m, vector<int>(n, 0));

        // t[i][j] = total square submatrices (having 1s) ending at cell [i][j]

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(i==0 || j==0){
                    t[i][j] = matrix[i][j];
                }

                else if(matrix[i][j] == 1){
                    t[i][j] = 1 + min({t[i-1][j], t[i-1][j-1], t[i][j-1]});
                }
                result += t[i][j];
            }
        }
        return result;
    }
};