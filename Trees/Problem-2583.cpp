// Problem-2583: Kth Largest Sum in a Binary Tree

// You are given the root of a binary tree and a positive integer k.
// The level sum in the tree is the sum of the values of the nodes that are on the same level.
// Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
// Note that two nodes are on the same level if they have the same distance from the root.
// Example:
// Input: root = [5,8,9,2,1,3,7,4,6], k = 2
// Output: 13
// Explanation: The level sums are the following:
// - Level 1: 5.
// - Level 2: 8 + 9 = 17.
// - Level 3: 2 + 1 + 3 + 7 = 13.
// - Level 4: 4 + 6 = 10.
// The 2nd largest level sum is 13.

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        // BFS queue to traverse level by level
        queue<TreeNode*> q;
        q.push(root);

        std::vector<long long> levelSums;

        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;

            // current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levelSums.push_back(levelSum);
        }

        sort(levelSums.begin(), levelSums.end(), std::greater<long long>());

        // check if there are enough levels
        if (k > levelSums.size()) {
            return -1;
        }

        // k-th largest level sum
        return levelSums[k - 1];
    }
};