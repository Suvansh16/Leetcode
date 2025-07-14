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
int max_height;
int sum;
void solve(TreeNode*root,int height){
if(!root->left && !root->right)
{
    if(height>max_height)
    {
        max_height=height;
        sum=root->val;
    }
    else if(height==max_height)
    {
        sum+=root->val;

    }
    return;
}
    if(root->left)
    solve(root->left,height+1);
    if(root->right)
    solve(root->right,height+1);
}


    int deepestLeavesSum(TreeNode* root) {
        max_height=0,sum=0;
        solve(root,0);
        return sum;
    }
};