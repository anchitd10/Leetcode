// Problem-2458: Height of Binary Tree After Subtree Removal Queries

// You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
// You have to perform m independent queries on the tree where in the ith query you do the following:
// Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
// Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

// Note:
// The queries are independent, so the tree returns to its initial state after each query.
// The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
//  Example 1:
// Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
// Output: [2]
// Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
// The height of the tree is 2 (The path 1 -> 3 -> 2).

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
    // Helper function to calculate heights and depths of each node
    int calculateHeight(TreeNode* node, unordered_map<int, int>& height, unordered_map<int, int>& depth, int d) {
        if (!node) return -1;
        depth[node->val] = d;
        int leftHeight = calculateHeight(node->left, height, depth, d + 1);
        int rightHeight = calculateHeight(node->right, height, depth, d + 1);
        height[node->val] = 1 + max(leftHeight, rightHeight);
        return height[node->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> height;  // height of each subtree rooted at each node
        unordered_map<int, int> depth;   // depth of each node
        unordered_map<int, vector<int>> depth_heights; // heights at each depth level
        
        // heights and depths of all nodes
        calculateHeight(root, height, depth, 0);
        
        // find the top two max heights for each level
        for (auto& [val, h] : height) {
            int d = depth[val];
            depth_heights[d].push_back(h);
        }
        
        // sort heights at each depth and keep only the top two
        unordered_map<int, pair<int, int>> top_two_at_depth;
        for (auto& [d, heights] : depth_heights) {
            sort(heights.rbegin(), heights.rend());
            if (heights.size() == 1)
                top_two_at_depth[d] = {heights[0], -1};
            else
                top_two_at_depth[d] = {heights[0], heights[1]};
        }

        // answer each query
        vector<int> answer;
        int initial_height = height[root->val];
        for (int q : queries) {
            int d = depth[q];
            int h = height[q];
            int max_height_after_removal;
            
            // determine the new height if this subtree is removed
            if (top_two_at_depth[d].first == h)
                max_height_after_removal = initial_height - h + top_two_at_depth[d].second;
            else
                max_height_after_removal = initial_height;

            answer.push_back(max_height_after_removal);
        }
        
        return answer;
    }
};