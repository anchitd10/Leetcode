// Problem-554: Brick Wall

// There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.
// Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
// Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.
// Example 1:
// Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
// Output: 2


class Solution {
public:
    // intuition: check for every row and see where the bricks are having a break so that when brick is cut from that column index then then it will be clear (no brick in path). finally get the column with the most breaks and subract it from the total walls.

    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> mp;
        int breaks = 0;

        for(int i=0; i<n; i++){
            long long sum = 0;
            for(int j=0; j < wall[i].size() - 1; j++){   // size - 1 becuase we are told not to consider the last break
                sum += wall[i][j];
                mp[sum]++;
                breaks = max(breaks, mp[sum]);
            }
        }

        return n - breaks;;
    }
};