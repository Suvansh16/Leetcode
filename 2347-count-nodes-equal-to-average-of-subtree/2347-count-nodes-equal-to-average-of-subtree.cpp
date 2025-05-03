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
unordered_map<TreeNode*,pair<int,int>>map;
// unordered_map<TreeNode*,int>map_size;
pair<int,int> solve(TreeNode*root){
if(root==NULL)
return {0,0};
pair<int,int>left=solve(root->left);
pair<int,int> right=solve(root->right);

return map[root]={left.first+right.first+root->val,left.second+right.second+1};
}
// int cal_size(TreeNode*root)
// {
//     if(root==NULL)
//     return 0;
//     int left_size=cal_size(root->left);
//     int right_size=cal_size(root->right);
//     return map_size[root]=left_size+right_size+1;
// }
int count=0;
void check(TreeNode*root)
{
    if(root==NULL)
    return ;
    check(root->left);
    check(root->right);
    if(map[root].first/map[root].second==root->val)
    {
        count++;
    }

}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        // cal_size(root);
        
        check(root);
        return count;
    }
};