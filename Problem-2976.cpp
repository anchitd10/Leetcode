// Problem-2976: Minimum Cost to Convert String

// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].
// You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.
// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].
// Example 1:
// Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
// Output: 28
// Explanation: To convert the string "abcd" to string "acbe":
// - Change value at index 1 from 'b' to 'c' at a cost of 5.
// - Change value at index 2 from 'c' to 'e' at a cost of 1.
// - Change value at index 2 from 'e' to 'b' at a cost of 2.
// - Change value at index 3 from 'd' to 'e' at a cost of 20.
// The total cost incurred is 5 + 1 + 2 + 20 = 28.
// It can be shown that this is the minimum possible cost.

// Floyd-Warshall Algorithm
class Solution {
public:
    void floydWarshall(vector<vector<long long>> &adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
        for(int i=0; i<original.size(); i++){
            int s = original[i] - 'a';
            int t = changed[i] - 'a';

            adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
        }

        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k]+ adjMatrix[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));

        floydWarshall(adjMatrix, original, changed, cost);
        long long ans = 0;

        for(int i=0; i<source.length(); i++){
            if(source[i] == target[i]){
                continue;
            }

            if(adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX){
                return -1;
            }

            ans += adjMatrix[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};