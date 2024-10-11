// Problem-1942: The Number of the Smallest Unoccupied Chair

// There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.
// For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
// When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.
// You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.
// Return the chair number that the friend numbered targetFriend will sit on.
// Example 1:
// Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
// Output: 1
// Explanation: 
// - Friend 0 arrives at time 1 and sits on chair 0.
// - Friend 1 arrives at time 2 and sits on chair 1.
// - Friend 1 leaves at time 3 and chair 1 becomes empty.
// - Friend 0 leaves at time 4 and chair 0 becomes empty.
// - Friend 2 arrives at time 4 and sits on chair 0.
// Since friend 1 sat on chair 1, we return 1.

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        // Step 1: Sort friends by their arrival times, keeping track of their indices
        vector<pair<int, int>> events;  // Pair of {arrival time, index}
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], i});
        }
        sort(events.begin(), events.end());
        
        // Step 2: Use two priority queues:
        // `availableChairs` - to get the smallest unoccupied chair
        // `occupiedChairs` - to track when friends leave and which chair becomes free
        
        priority_queue<int, vector<int>, greater<int>> availableChairs;  // Min-heap for available chairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;  // Min-heap of {leaving time, chair number}
        
        // Initially all chairs are available, so we push chairs 0, 1, 2, ..., n-1 into availableChairs
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
        
        // Step 3: Process each friend's arrival
        for (const auto& event : events) {
            int arrivalTime = event.first;
            int friendIndex = event.second;
            
            // Before a new friend arrives, process all friends who are leaving by the current time
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrivalTime) {
                availableChairs.push(occupiedChairs.top().second);  // Free up the chair
                occupiedChairs.pop();
            }
            
            // Assign the smallest available chair to the arriving friend
            int assignedChair = availableChairs.top();
            availableChairs.pop();
            
            // If the current friend is the targetFriend, return the chair number
            if (friendIndex == targetFriend) {
                return assignedChair;
            }
            
            //add the current friend's leaving time and assigned chair to occupiedChairs
            occupiedChairs.push({times[friendIndex][1], assignedChair});
        }
        
        return -1;
    }
};