// Problem-1346: Check if N and its Double Exists

// Given an array arr of integers, check if there exist two indices i and j such that :
// - i != j
// - 0 <= i, j < arr.length
// - arr[i] == 2 * arr[j]
// Example 1:
// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]


// brute force
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && arr[i] == (2*arr[j])){
                    return true;
                }
            }
        }
        return false;
    }
};

// hash table
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            if(st.find(arr[i]*2) != st.end()){
                return true;
            }
            else if(arr[i]%2 == 0 && st.find(arr[i]/2) != st.end()){
                return true;
            }
            st.insert(arr[i]);
        }
        return false;
    }
};