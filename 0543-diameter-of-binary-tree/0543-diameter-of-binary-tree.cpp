class Solution {
public:
    int ans = 0;

    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        // update diameter (edges in path = left height + right height)
        ans = max(ans, left + right);

        // return height of current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
