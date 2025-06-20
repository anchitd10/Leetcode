// Problem-3443: Maximum Manhattan Distance After K Changes

// You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:
// - 'N' : Move north by 1 unit.
// - 'S' : Move south by 1 unit.
// - 'E' : Move east by 1 unit.
// - 'W' : Move west by 1 unit.
// Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.
// Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.
// The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
// Example 1:
// Input: s = "NWSE", k = 1
// Output: 3
// Explanation:
// Change s[2] from 'S' to 'N'. The string s becomes "NWNE".
//         - Movement	   Position (x, y)	Manhattan Distance	Maximum
//         - s[0] == 'N'	   (0, 1)	        0 + 1 = 1	       1
//         - s[1] == 'W'	   (-1, 1)	        1 + 1 = 2	       2
//         - s[2] == 'N'	   (-1, 2)	        1 + 2 = 3	       3
//         - s[3] == 'E'	   (0, 2)	        0 + 2 = 2	       3
// The maximum Manhattan distance from the origin that can be achieved is 3. Hence, 3 is the output.


class Solution {
public:
    int maxDistance(string s, int k) {
        int north = 0;
        int south = 0;
        int west = 0;
        int east = 0;

        int maxMD = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'N')
                north++;
            else if (s[i] == 'S')
                south++;
            else if (s[i] == 'W')
                west++;
            else if (s[i] == 'E')
                east++;

            int currMD = abs(north - south) + abs(west - east);

            int steps = i + 1;
            int wasted = steps - currMD;

            int extra = 0;
            if (wasted != 0) { // it means that we can maximise the dist as
                               // steps != currMD
                extra = min(2 * k, wasted);
            }

            int finalMD = currMD + extra;
            maxMD = max(maxMD, finalMD);
        }

        return maxMD;
    }
};