// Problem-1072: Flip Columns For Maximum Number of Equal Rows

// You are given an m x n binary matrix matrix.
// You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
// Return the maximum number of rows that have all values equal after some number of flips.
// Example 1:
// Input: matrix = [[0,1],[1,1]]
// Output: 1
// Explanation: After flipping no values, 1 row has all values equal.

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[1].size();
        
        unordered_map<string, int> mp;

        for(auto &row : matrix){
            string rowNature = "";

            int firstVal = row[0];
            for(int col = 0; col < n; col++){
                rowNature += (row[col] == firstVal) ? "S" : "B";
            }

            mp[rowNature]++;
        }

        int maxRows = 0;
        for(auto &it : mp){
            maxRows = max(maxRows, it.second);
        }

        return maxRows;
    }
};