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
unordered_map<TreeNode*,int>map;
unordered_map<TreeNode*,int>map_size;
int solve(TreeNode*root){
if(root==NULL)
return 0;
int left_sum=solve(root->left);
int right_sum=solve(root->right);

return map[root]=left_sum+right_sum+root->val;
}
int cal_size(TreeNode*root)
{
    if(root==NULL)
    return 0;
    int left_size=cal_size(root->left);
    int right_size=cal_size(root->right);
    return map_size[root]=left_size+right_size+1;
}
int count=0;
void check(TreeNode*root)
{
    if(root==NULL)
    return ;
    check(root->left);
    check(root->right);
    if(map[root]/map_size[root]==root->val)
    {
        count++;
    }

}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        cal_size(root);
        
        check(root);
        return count;
    }
};