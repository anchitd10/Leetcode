// Problem-2418: Sort the people

// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
// For each index i, names[i] and heights[i] denote the name and height of the ith person.
// Return names sorted in descending order by the people's heights.
// Example:
// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
// Output: ["Mary","Emma","John"]
// Explanation: Mary is the tallest, followed by Emma and John.

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size(), temp = 0;
        string name;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (heights[j] < heights[j + 1]) {
                    temp = heights[j + 1];
                    heights[j + 1] = heights[j];
                    heights[j] = temp;

                    name = names[j + 1];
                    names[j + 1] = names[j];
                    names[j] = name;
                }
            }
        }

        return names;
    }
};