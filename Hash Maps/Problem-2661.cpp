// Problem-2661: First Completely Painted Row or Column

// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
// Return the smallest index i at which either a row or a column will be completely painted in mat.
// Example 1:
// image explanation for example 1
// Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
// Output: 2
// Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

class Solution {
public:
    bool checkRowPainted(vector<vector<int>>& mat, int row){
        for(int col=0; col < mat[0].size(); col++){
            if(mat[row][col] > 0){
                return false;
            }
        }
        return true;
    }

    bool checkColPainted(vector<vector<int>>& mat, int col){
        for(int row=0; row < mat[0].size(); row++){
            if(mat[row][col] > 0){
                return false;
            }
        }
        return true;
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mp;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int val = mat[i][j];
                mp[val] = {i,j};
            }
        }

        vector<int> rowCountPaint(m, 0);
        vector<int> colCountPaint(n, 0);

        for(int i=0; i<arr.size(); i++){
            int val = arr[i];
            auto [row,col] = mp[val];

            rowCountPaint[row]++;
            colCountPaint[col]++;

            if(rowCountPaint[row] == n || colCountPaint[col] == m){
                return i;
            }
        }



        // for(int i=0; i<arr.size(); i++){
        //     int val = arr[i];

        //     auto [row,col] = mp[val];
        //     mat[row][col] *= -1; //painted

        //     if(checkRowPainted(mat,row) || checkColPainted(mat,col)){
        //         return i;
        //     }
        // }

        
        return -1;
    }
};