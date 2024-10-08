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
int global;
void dfs(TreeNode*root,vector<int>&ans,int level)
{
    if(root==NULL)
    return;
    if(level>global){
        ans.push_back(root->val);
        global=level;
    }
    if(root->right)
    {
        dfs(root->right,ans,level+1);
    }
    if(root->left)
    {
        dfs(root->left,ans,level+1);
    }
}
    vector<int> rightSideView(TreeNode* root) {
        global=0;
        if(root==NULL)
        return {};
        vector<int>ans;
        dfs(root,ans,1);
        return ans;
    }
};