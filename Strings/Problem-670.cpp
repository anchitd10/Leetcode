// Problem-670: Maximum Swap

// You are given an integer num. You can swap two digits at most once to get the maximum valued number.
// Return the maximum valued number you can get.
// Example 1:
// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        
        // last occurrence of each digit (0-9).
        int last[10] = {0};
        
        // last occurrence array.
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
    
        for (int i = 0; i < n; ++i) {
            // larger digit present later in the string.
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};
