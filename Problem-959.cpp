// Problem-959: Regions Cut by Slashes

// An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
// Given the grid grid represented as a string array, return the number of regions.
// Note that backslash characters are escaped, so a '\' is represented as '\\'.
// Input: grid = ["/\\","\\/"]
// Output: 5
// Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

class Solution {
public:
    void numberOfIslandsDFS(vector<vector<int>>& matrix, int i, int j){
        if(i<0 || i>= matrix.size() || j<0 || j>= matrix[0].size() || matrix[i][j] ==1){
            return;
        }

        matrix[i][j] = 1;

        numberOfIslandsDFS(matrix, i+1, j);
        numberOfIslandsDFS(matrix, i-1, j);
        numberOfIslandsDFS(matrix, i, j+1);
        numberOfIslandsDFS(matrix, i, j-1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0;

        vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3] = 1;
                }

                else if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    numberOfIslandsDFS(matrix, i, j);
                    regions += 1;
                }
            }
        }
        return regions;
    }
};