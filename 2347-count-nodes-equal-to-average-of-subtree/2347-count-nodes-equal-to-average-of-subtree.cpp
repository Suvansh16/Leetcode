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
 */class Solution {
public:
    // Map to store subtree sum and count of nodes for each TreeNode
    unordered_map<TreeNode*, pair<int, int>> map;

    // Helper function to calculate sum and count of nodes in the subtree rooted at 'root'
    pair<int, int> solve(TreeNode* root) {
        // Base case: if the current node is NULL, return sum = 0 and count = 0
        if (root == NULL)
            return {0, 0};

        // Recursively solve for left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        // Calculate current subtree's sum and count
        int totalSum = left.first + right.first + root->val;
        int totalCount = left.second + right.second + 1;

        // Store result in the map for current node
        return map[root] = {totalSum, totalCount};
    }

    int count = 0; // To keep track of nodes matching the condition

    // Helper function to check each node if its value equals the average of its subtree
    void check(TreeNode* root) {
        if (root == NULL)
            return;

        // Recur for left and right subtrees
        check(root->left);
        check(root->right);

        // Get sum and count of current subtree
        int sum = map[root].first;
        int nodeCount = map[root].second;

        // If the node's value is equal to the average of its subtree, increment count
        if (sum / nodeCount == root->val) {
            count++;
        }
    }

    // Main function to return the number of nodes whose value equals the average of their subtree
    int averageOfSubtree(TreeNode* root) {
        solve(root);   // Fill the map with subtree sum and count for all nodes
        check(root);   // Traverse and check the condition for each node
        return count;  // Return the final count
    }
};
