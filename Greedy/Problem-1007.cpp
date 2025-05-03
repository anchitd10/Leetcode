// Problem-1007: Minimum Domino Rotations For Equal Row

// In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
// We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
// Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
// If it cannot be done, return -1.
// Example:
// Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// Output: 2
// Explanation: 
// The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
// If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.


class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX;
        for (int val = 1; val <= 6; ++val) {
            int top_swaps = 0, bottom_swaps = 0;
            bool valid = true;
            for (int i = 0; i < tops.size(); ++i) {
                if (tops[i] != val && bottoms[i] != val) {
                    valid = false;
                    break;
                }
                if (tops[i] != val) top_swaps++;
                if (bottoms[i] != val) bottom_swaps++;
            }
            if (valid)
                res = min(res, min(top_swaps, bottom_swaps));
        }
        return res == INT_MAX ? -1 : res;
    }
};