// Problem-2406: Divide intervals into Minimum Number of Groups

// You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].
// You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.
// Return the minimum number of groups you need to make.
// Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.
// Example 1:
// Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
// Output: 3
// Explanation: We can divide the intervals into the following groups:
// - Group 1: [1, 5], [6, 8].
// - Group 2: [2, 3], [5, 10].
// - Group 3: [1, 10].
// It can be proven that it is not possible to divide the intervals into fewer than 3 groups.

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals)); //sort groups based on starting points
        
        priority_queue<int, vector<int>, greater<int>> pq; //min heap

        for(vector<int>& i : intervals){
            int start = i[0];
            int end = i[1];

            if(!pq.empty() && start > pq.top()){ //replace the top element with the next group whose starting is more than current end
                pq.pop();
            }
            pq.push(end);
        }  
        return pq.size();      
    }
};