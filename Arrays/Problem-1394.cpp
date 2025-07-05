// Problem-1394: Find Lucky Integer in an Array

// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
// Return the largest lucky integer in the array. If there is no lucky integer return -1.
// Example 1:
// Input: arr = [2,2,3,4]
// Output: 2
// Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
// Example 2:
// Input: arr = [1,2,2,3,3,3]
// Output: 3
// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.


// Brute Force
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        int luckyInt = -1;

        for(int i : arr){
            freq[i]++;
        }

        for(auto it : freq){
            if(it.first == it.second){
                luckyInt = max(luckyInt, it.first);
            }
        }

        return luckyInt;
    }
};

// Constant Space
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501,0);  //constraint given
        int luckyInt = -1;

        for(int num : arr){
            freq[num]++;
        }

        for(int i=1; i<501; i++){  //start from 1 as freq[0] == 0 always in this question
            if(freq[i] == i){
                luckyInt = max(luckyInt, i);
            }
        }

        return luckyInt;
    }
};