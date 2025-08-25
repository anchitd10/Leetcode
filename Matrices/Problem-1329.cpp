// Problem-1329: Sort the Matrix Diagonally

// A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
// Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.



// Concept: Hashing + Sorting
// Tip: use [i-j] for diagonal traversal of top left to bottom right
//      use [i+j] for diagonal traversal of bottom left to top right


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }

        for(auto &it : mp){
            sort(it.second.begin(), it.second.end());
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return mat;
    }
};