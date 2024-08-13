// Problem-40: Combination Sum II

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.
// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

//backtracking
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx, vector<vector<int>>& result){
        if(target < 0){
            return;
        }
        
        if(target == 0){
            result.push_back(curr);
            return;
        }

        for(int i=idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }

            curr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], curr, i+1, result);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(begin(candidates), end(candidates));
        solve(candidates, target, curr, 0, result);

        return result;
    }
};