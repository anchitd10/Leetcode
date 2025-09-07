// Problem-1304: Find N Unique Integers Sum up to Zero

// Given an integer n, return any array containing n unique integers such that they add up to 0
// Example 1:
// Input: n = 5
// Output: [-7,-1,1,3,4]
// Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].


// Concept: just add the numbers from 1 to n/2 and their negative counterparts. If n is odd, add 0 at the end.

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int start = 1;
        int i = 0;
        
        while(i+1 < n) {
            result[i] = start;
            result[i+1] = -start;

            i+= 2;
            start++;
        }

        return result;
    }
};