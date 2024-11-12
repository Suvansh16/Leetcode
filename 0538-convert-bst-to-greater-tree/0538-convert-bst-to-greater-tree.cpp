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
void solve(TreeNode*&root,int &t)
{
    if(root==NULL)
        return;
    solve(root->right,t);
    root->val +=t;
    t = root->val;
    solve(root->left,t);
}
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
        return NULL;
        int t = 0;
        solve(root,t);
        return root;


    }
};