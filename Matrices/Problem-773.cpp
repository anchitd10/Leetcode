// Problem-773: Sliding Puzzle

// On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
// Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
// Example:
// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        
        string start = "";
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }
        
        vector<int> directions = {-1, 1, -3, 3};
        
        // BFS
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(start);
        visited.insert(start);
        int moves = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();
                
                if (curr == target) {
                    return moves;
                }
                
                int zeroIndex = curr.find('0');
                
                for (int dir : directions) {
                    int newIndex = zeroIndex + dir;
                    
                    if (newIndex >= 0 && newIndex < 6 && 
                        !(zeroIndex == 2 && dir == 1) && 
                        !(zeroIndex == 3 && dir == -1)) {
                        
                        swap(curr[zeroIndex], curr[newIndex]);
                        
                        if (visited.find(curr) == visited.end()) {
                            visited.insert(curr);
                            q.push(curr);
                        }
                        
                        swap(curr[zeroIndex], curr[newIndex]);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};