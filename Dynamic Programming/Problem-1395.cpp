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
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
 
        //count valid teams
        for (int j = 0; j < n; j++) {
            int less_left = 0, more_left = 0;
            int less_right = 0, more_right = 0;

            //count how many soldiers before 'j' are less or more
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) {
                    less_left++;
                } else if (rating[i] > rating[j]) {
                    more_left++;
                }
            }

            //count how many soldiers after 'j' are less or more
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j]) {
                    less_right++;
                } else if (rating[k] > rating[j]) {
                    more_right++;
                }
            }

            //count increasing teams (less_left * more_right)
            count += less_left * more_right;

            //count decreasing teams (more_left * less_right)
            count += more_left * less_right;
        }

        return count;
    }
};