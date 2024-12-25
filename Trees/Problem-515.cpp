// Problem-515: Find Largest Value in Each Tree Row

// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
// Example 1:
// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]
// Example 2:
// Input: root = [1,2,3]
// Output: [1,3]

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(maxVal);
        }

        return result;
    }
};