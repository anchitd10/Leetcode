// Problem-386: Lexicographical Numbers

// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
// Example 1:
// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]


// DFS
class Solution {
public:
    void solve(int curr, int n, vector<int>& result){
        if(curr > n){
            return;
        }

        result.push_back(curr);

        for(int append = 0; append <=9; append++){
            int newNum = curr*10 + append;

            if(newNum > n){
                return;
            }

            solve(newNum, n, result);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for(int startNum = 1; startNum <=9; startNum++){
            solve(startNum, n, result);
        }

        return result;
    }
};