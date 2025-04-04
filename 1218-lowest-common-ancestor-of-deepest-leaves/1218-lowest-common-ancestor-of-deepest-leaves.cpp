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
TreeNode* solve(TreeNode*root,int depth,int len)
{
    if(len==depth-1)
    {
        return root;
    }
    if(root==NULL)
    return NULL;
    TreeNode*left=solve(root->left,depth,len+1);
    TreeNode*right=solve(root->right,depth,len+1);
    if(left && right)
    return root;
    return left?left:right;
}
int find_depth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    return 1+max(find_depth(root->left),find_depth(root->right));
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth=find_depth(root);
        return solve(root,depth,0);
    }
};