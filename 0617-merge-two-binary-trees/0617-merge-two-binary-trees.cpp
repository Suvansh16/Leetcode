class Solution {
public:
    void solve(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return;

        root1->val += root2->val;

        if (root2->left) {
            if (!root1->left)
                root1->left = root2->left;
            else
                solve(root1->left, root2->left);
        }

        if (root2->right) {
            if (!root1->right)
                root1->right = root2->right;
            else
                solve(root1->right, root2->right);
        }
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        solve(root1, root2);
        return root1;
    }
};
