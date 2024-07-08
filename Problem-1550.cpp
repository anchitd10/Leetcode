// Problem-1550: Three Consecutive Odds
// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
// Example 1:
// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                count++;
                if(count == 3){
                    return true;
                }
            }
            else{
                count=0;
            }
        }
        return false;
    }
};