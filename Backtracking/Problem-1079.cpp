// Problem-1079: Letter Tile Possibilities

// You have n  tiles, where each tile has one letter tiles[i] printed on it.
// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
// Example 1:
// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:
// Input: tiles = "AAABBC"
// Output: 188

class Solution {
public:
    int n;

    void solve(string& tiles, vector<bool>& used, unordered_set<string>& result, string &curr){
        n = tiles.length();
        
        result.insert(curr);

        for(int i=0; i<n; i++){
            if(used[i]){
                continue;
            }

            used[i] = true;
            curr.push_back(tiles[i]);

            solve(tiles, used, result, curr);

            used[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.length();

        vector<bool> used(n, false);
        unordered_set<string> result;

        string curr = "";

        solve(tiles, used, result, curr);

        return result.size()-1;
    }
};