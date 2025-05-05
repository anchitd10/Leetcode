// Problem-1128: Number of Equivalent Domino Pairs

// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
// Example 1:
// Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
// Output: 3


// Brute Force
// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         int n = dominoes.size();
//         int count = 0;

//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 if((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) || (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


// Map of Pairs
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;

        for(auto &d : dominoes) {
            if(d[0] > d[1]) { //(2, 1) ---- (1, 2)
                swap(d[0], d[1]);
            }
            mp[{d[0], d[1]}]++;
        }

        int result = 0;

        for(auto &it : mp) {
            int freq = it.second;

            result += freq * (freq-1)/2; //freqC2
        }

        return result;
    }
};