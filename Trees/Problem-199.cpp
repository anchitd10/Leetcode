// Problem-199: Binary Tree Right Side View

// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// Example 1:
// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]


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
    void Right(TreeNode *root, int level, vector<int>& res){
        if(root == NULL){
            return;
        }
        
        if(res.size() == level){
            res.push_back(root->val);
        }
        
        Right(root->right, level+1, res);
        Right(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        Right(root, 0, res);
        return res;
    }
};