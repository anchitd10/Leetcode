// Problem-144: Binary Tree Preorder Traversal

// Given the root of a binary tree, return the preorder traversal of its nodes' values.


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
private:
    void preOrder(TreeNode* node, vector<int>& result){
        if(node == NULL){
            return;
        }

        result.push_back(node->val);
        preOrder(node->left, result);
        preOrder(node->right, result);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        preOrder(root, res);
        return res;
    }
};