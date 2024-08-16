// Problem-624: Maximum Distance in Arrays

// You are given m arrays, where each array is sorted in ascending order.
// You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.
// Return the maximum distance.
// Example 1:
// Input: arrays = [[1,2,3],[4,5],[1,2,3]]
// Output: 4
// Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDistance = 0;
        int minElement = arrays[0][0];
        int maxElement = arrays[0][arrays[0].size()-1];

        for (int i=1; i<arrays.size(); i++){
            int currMin = arrays[i][0];
            int currMax = arrays[i][arrays[i].size() - 1];
            
            int dist_min = abs(currMin - maxElement);
            int dist_max = abs(currMax - minElement);

            maxDistance = max(maxDistance, max(dist_min, dist_max));

            minElement = min(minElement, currMin);
            maxElement = max(maxElement, currMax);
        }
        return maxDistance;
    }
};