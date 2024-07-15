// Problem-2196: Create Binary Tree from descriptions

// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,
// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.
// Example:
// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> hasParent;

        for(auto description: descriptions){
            int parentVal = description[0], childVal = description[1], isLeft = description[2];
            TreeNode *parentNode = nullptr, *childNode = nullptr;

            if(mp.find(parentVal) == mp.end()) parentNode = new TreeNode(parentVal);
            else parentNode = mp[parentVal];

            if(mp.find(childVal) == mp.end()) childNode = new TreeNode(childVal);
            else childNode = mp[childVal];

            if(isLeft) parentNode->left = childNode;
            else parentNode->right = childNode;

            hasParent[childVal] = true;
            mp[childVal] = childNode;
            mp[parentVal] = parentNode;
        }
        TreeNode* rootNode = nullptr;
        for(auto& [nodeVal, node] :mp){
            if(!hasParent[nodeVal]) rootNode = node;
        }

        return rootNode;

    }
};