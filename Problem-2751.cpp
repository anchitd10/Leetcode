// Problem-2751: Robot Collisions

// There are n 1-indexed robots, each having a position on a line, health, and movement direction.
// You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.
// All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.
// If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.
// Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.
// Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.
// Note: The positions may be unsorted.
// Example:
// Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
// Output: [14]
// Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ids;
        for(int i=0; i<n; i++){
            ids.push_back(i);
        }

        auto compare = [&](int id1, int id2){
            return positions[id1] <= positions[id2];
        };
        sort(ids.begin(), ids.end(), compare);
        
        stack<int> st;
        for(auto id : ids){
            if(directions[id]  == 'R'){
                st.push(id);
            }
            else{
                while(!st.empty() &&  healths[id] > 0){
                    if(healths[id] > healths[st.top()]){
                        healths[id]--;
                        healths[st.top()]=0;
                        st.pop();
                    }
                    else if(healths[id] < healths[st.top()]){
                        healths[id] = 0;
                        healths[st.top()]--;
                    }
                    else{
                        healths[id] = 0;
                        healths[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};