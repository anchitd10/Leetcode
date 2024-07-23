// Problem-1110: Delete Nodes and Return Forest

// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest. You may return the result in any order.
// Example:
// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]



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
    vector<TreeNode*> ans;
    void dfs(TreeNode* root, unordered_set<int>&s, bool is_root){
        if(root == nullptr){
            return;
        }

        if(s.find(root->val) != s.end()){
            dfs(root->left, s, true);
            dfs(root->right, s, true);
        }
        else{
            if(is_root) ans.push_back(root);

            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;
            if(root->left){
                if(s.find(root->left->val) != s.end()){
                    root->left = nullptr;
                }
            }
            if(root->right){
                if(s.find(root->right->val) != s.end()){
                    root->right = nullptr;
                }
            }
            dfs(leftNode, s, false);
            dfs(rightNode, s, false);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ans.clear();
        unordered_set<int> s(to_delete.begin(), to_delete.end());

        dfs(root, s, true);

        return ans;
    }
};