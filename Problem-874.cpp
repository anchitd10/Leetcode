// Problem-874: Walking Robot Simulatuion

// A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:
// -2: Turn left 90 degrees.
// -1: Turn right 90 degrees.
// 1 <= k <= 9: Move forward k units, one unit at a time.
// Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.
// Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).
// Note:
// North means +Y direction.
// East means +X direction.
// South means -Y direction.
// West means -X direction.
// There can be obstacle in [0,0]. 
// Example:
// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
// Output: 65
// Explanation: The robot starts at (0, 0):
// 1. Move north 4 units to (0, 4).
// 2. Turn right.
// 3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
// 4. Turn left.
// 5. Move north 4 units to (1, 8).
// The furthest point the robot ever gets from the origin is (1, 8), which squared is 12 + 82 = 65 units away.

class Solution {
public:
    // when -1 then x=y, y=-x everytime -1 is called to move 90 degrees right
    // when -2 then x=-y and y=x everytime -2 is called to move 90 degrees left

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(vector<int>& obs: obstacles){
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxDist = 0;

        //point to north direction
        pair<int, int> direction = {0,1}; //north

        for(int i=0; i< commands.size(); i++){
            if(commands[i] == -2){
                direction = {-direction.second, direction.first};
            } else if(commands[i] == -1){
                direction = {direction.second, -direction.first};
            } else {
                for(int step = 0; step<commands[i]; step++){
                    int newX = x + direction.first;
                    int newY = y + direction.second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);

                    if(st.find(nextKey) != st.end()){
                        break;
                    }

                    x = newX;
                    y = newY;
                }
            }
            maxDist = max(maxDist, x*x + y*y);
        }
        return maxDist;
    }
};
