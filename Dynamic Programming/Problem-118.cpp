// Problem-118: Pascal's Triangle

// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=0; i<numRows; i++){
            vector<int> v(i+1,1);

            for(int j=1; j<i; j++){
                // i -> current row, i-1 -> previous row
                // j to access first element in prev row and (j-1) to access next element in prev row
                v[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(v);
        }
        return ans;
    }
};