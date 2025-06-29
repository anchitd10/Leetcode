// Problem-11: Container With Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.
// Example:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
// In this case, the max area of water (blue section) the container can contain is 49.


// Two Pointer
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j = n-1;
        int maxWater = 0;

        while(i < j){
            int width = j-i;
            int currHeight = min(height[i], height[j]);
            int area = width * currHeight;

            maxWater = max(maxWater,area);

            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }

        return maxWater;
    }
};