// Problem-1530: Number of good leaf nodes pair

// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
// Return the number of good leaf node pairs in the tree.
// Example:
// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};
        
        if (!node->left && !node->right) return {1};
        
        vector<int> leftDistances = dfs(node->left, distance, count);
        vector<int> rightDistances = dfs(node->right, distance, count);
        
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    count++;
                }
            }
        }
        
        vector<int> result;
        for (int l : leftDistances) {
            if (l + 1 <= distance) {
                result.push_back(l + 1);
            }
        }
        for (int r : rightDistances) {
            if (r + 1 <= distance) {
                result.push_back(r + 1);
            }
        }
        
        return result;
    }
};