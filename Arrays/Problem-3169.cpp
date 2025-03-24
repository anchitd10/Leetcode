// Problem-3169: Count Days Without Meetings

// You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
// Return the count of days when the employee is available for work but no meetings are scheduled.
// Note: The meetings may overlap.
// Example 1:
// Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
// Output: 2
// Explanation:
// There is no meeting scheduled on the 4th and 8th days.
// Example 2:
// Input: days = 5, meetings = [[2,4],[1,3]]
// Output: 1
// Explanation:
// There is no meeting scheduled on the 5th day.


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(begin(meetings), end(meetings));

        int result = 0;
        int start = 0;
        int end = 0;

        for(auto &meet : meetings){
            if(meet[0] > end){
                result += meet[0] - end - 1;
            }
            end = max(end, meet[1]);
        }

        if(days > end){
            result += days-end;
        }
        
        return result;
    }
};