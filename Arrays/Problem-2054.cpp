// Problem-2054: Two Best Non-Overlapping Events

// You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
// Return this maximum sum.
// Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.
// Example 1:
// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int binarySearch(vector<vector<int>>& events, int endTime) {
        int l = 0;
        int r = n - 1;
        int result = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (events[mid][0] > endTime) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& events, int i, int count) {
        if (count == 2 || i >= n) {
            return 0;
        }

        if (dp[i][count] != -1) {
            return dp[i][count];
        }

        int nextValidEventIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + (nextValidEventIndex == -1 ? 0 : solve(events, nextValidEventIndex, count + 1));

        int not_take = solve(events, i + 1, count);

        dp[i][count] = max(take, not_take);
        return dp[i][count];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(begin(events), end(events));

        dp = vector<vector<int>>(n, vector<int>(3, -1));
        return solve(events, 0, 0);
    }
};
