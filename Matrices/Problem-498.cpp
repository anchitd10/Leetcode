// Problem-498: Diagonal Traverse

// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

// Concept: Hashing + Simulation
// Tip: use [i+j] for diagonal traversal of bottom left to top right and use flip bool to reverse the vector and push all to result vector

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int, vector<int>> mp;
        vector<int> result;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for(auto &it : mp){
            if(flip){
                reverse(it.second.begin(), it.second.end());
            }

            for(int &num : it.second){
                result.push_back(num);
            }

            flip = !flip;
        }

        return result;
    }
};
