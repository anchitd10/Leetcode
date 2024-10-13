// Problem-632: Smallest Range Covering Elements from K Lists

// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// Example 1:
// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> vec(k, 0);
        vector<int> resultRange = {-100000, 100000};

        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        int minElementListIndex = 0;

        while (true) {
            minElement = INT_MAX;
            maxElement = INT_MIN;

            //min and max elements in the current window
            for (int i = 0; i < k; i++) {
                int listIndex = i;
                int elementIndex = vec[i];
                int element = nums[listIndex][elementIndex];

                if (element < minElement) {
                    minElement = element;
                    minElementListIndex = listIndex;
                }

                maxElement = max(maxElement, element);
            }

            //define range
            if (maxElement - minElement < resultRange[1] - resultRange[0]) {
                resultRange[0] = minElement;
                resultRange[1] = maxElement;
            }

            //shorten the range by moving minElement index
            int nextIndex = vec[minElementListIndex] + 1;
            if (nextIndex >= nums[minElementListIndex].size()) {
                break; //stop if no more elements in one of the lists
            }

            vec[minElementListIndex] = nextIndex;
        }
        
        return resultRange;
    }
};
