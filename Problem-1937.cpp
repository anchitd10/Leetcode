// Problem-1937: Maximum Number of Points with Cost

// You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.
// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
// Return the maximum number of points you can achieve.
// abs(x) is defined as:
// x for x >= 0.
// -x for x < 0.
// Example:
// Input: points = [[1,2,3],[1,5,1],[3,1,1]]
// Output: 9
// Explanation:
// The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
// You add 3 + 5 + 3 = 11 to your score.
// However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
// Your final score is 11 - 2 = 9.

//brute force of dp  --->  manually calculate sum from prev row for each column
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();  //row
        int n = points[0].size();  //column

        vector<long long> prev(n);
        int score = 0;

        for(int col=0; col<n; col++){
            prev[col] = points[0][col];
        }
        for(int row=1; row<m; row++){
            vector<long long> curr(n);
            for(int col=0; col<n; col++){
                for(int k=0; k<n; k++){  //iterate through previous row
                curr[col] = max(curr[col], prev[k] + points[row][col] - abs(col-k));
                }
            }
            prev = curr;
        }
        return *max_element(begin(prev), end(prev));
    }
};