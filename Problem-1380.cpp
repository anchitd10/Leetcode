// Problem-1380: Lucky Numbers in a matrix

// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
// Example 1:
// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.



// Brute Force
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int row=i, col=j, minRow=INT_MAX, maxCol=INT_MIN;
                for(int k=0; k<m; k++){
                    minRow = min(minRow, matrix[row][k]);
                }
                for(int k=0;k<n; k++){
                    maxCol = max(maxCol, matrix[k][col]);
                }

                if(matrix[i][j] == minRow && matrix[i][j] == maxCol){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};


// Using two arrays for min and max
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> row(n, INT_MAX), col(m, INT_MIN), ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == row[i] && matrix[i][j] == col[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};

//Optimal-1-------->First check min element row then max element in that col and compare
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int row=i, minRow=INT_MAX, minRowCol;
            for(int j=0; j<m; j++){
                if(minRow > matrix[row][j]){
                    minRow = matrix[row][j];
                    minRowCol = j;
                }
            }

            int col = minRowCol, maxCol=INT_MIN, maxColRow;
            for(int k=0; k<n; k++){
                if(maxCol < matrix[k][col]){
                    maxCol = matrix[k][col];
                    maxColRow = k;
                }
            }

            if(i == maxColRow){
                ans.push_back(matrix[i][minRowCol]);
            }
        }
        return ans;
    }
};