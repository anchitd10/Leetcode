// Problem-2096: Step-By-Step Directions From a Binary Tree Node to Another

// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.
// Example:
// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

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


// lowest common ancestor approach
class Solution {
public:
    TreeNode* lca(TreeNode* node, int p, int q) {
        if(node == nullptr) return node;

        TreeNode* leftSide = lca(node->left, p, q);
        TreeNode* rightSide = lca(node->right, p, q);

        if( (leftSide && rightSide) || (node->val == p || node->val == q) )
            return node;
        return (leftSide == nullptr) ? rightSide : leftSide;   
    }

    string lcaToStart, lcaToEnd;
    void dfs(TreeNode* node, string& pathString, int p, int q){
        if(node == nullptr) return;
        if(node->val == p) lcaToStart = pathString;
        if(node->val == q) lcaToEnd = pathString;

        pathString.push_back('L');
        dfs(node->left, pathString, p, q);
        pathString.pop_back();

        pathString.push_back('R');
        dfs(node->right, pathString, p, q);
        pathString.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue){
        TreeNode * lcaNode = lca(root, startValue, destValue);

        string pathString = "";
        dfs(lcaNode, pathString, startValue, destValue);

        for(auto& ch: lcaToStart) ch = 'U';
        return lcaToStart + lcaToEnd;
    }
};