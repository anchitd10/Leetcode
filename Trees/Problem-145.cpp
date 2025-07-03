Problem-145: Binary Tree Postorder Traversal

// Given the root of a binary tree, return the postorder traversal of its nodes' values.
// Example:
// Input: root = [1,null,2,3]
// Output: [3,2,1]


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
    void postOrder(TreeNode* root, vector<int>& result){
        if(!root){
            return;
        }

        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        postOrder(root, result);

        return result;
    }
};