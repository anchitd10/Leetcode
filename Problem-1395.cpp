// Problem-1395: Count number of teams

// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
// You have to form a team of 3 soldiers amongst them under the following rules:
// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
// Example 1:
// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

class Solution {
public:
    int count = 0;
    void solve(vector<int>& rating, vector<int>& use, int index, int prev) {
        if (use.size() == 3) {
            count++;
            return;
        }
        for (int i = index; i < rating.size(); i++) {
            if (prev == -1 || rating[i] > rating[prev]) {
                use.push_back(rating[i]);
                solve(rating, use, i + 1, i);
                use.pop_back();
            }
        }
    }

    void solve2(vector<int>& rating, vector<int>& use2, int index, int prev) {
        if (use2.size() == 3) {
            count++;
            return;
        }
        for (int i = index; i < rating.size(); i++) {
            if (prev == -1 || rating[i] < rating[prev]) {
                use2.push_back(rating[i]);
                solve2(rating, use2, i + 1, i);
                use2.pop_back();
            }
        }
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> use;
        vector<int> use2;
        solve(rating, use, 0, -1);
        solve2(rating, use2, 0, -1);
        return count;
    }
};