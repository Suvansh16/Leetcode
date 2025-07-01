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
int ans=INT_MIN;
int dfs(TreeNode*root)
{
    if(root==NULL)
    return 0;
    int left=dfs(root->left);
    int right=dfs(root->right);
    int max1=root->val;
    int max2=root->val+left+right;
    int max3=root->val+max(left,right);
    ans=max({ans,max1,max2,max3});
    return max(max3,max1);
}
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};