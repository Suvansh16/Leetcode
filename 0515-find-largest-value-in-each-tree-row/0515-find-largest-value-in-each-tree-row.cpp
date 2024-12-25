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
vector<int>ans;
void DFS(TreeNode*root,int depth)
{
    if(root==NULL)
    return;
    if(depth==ans.size())
    ans.push_back(root->val);
    else
    ans[depth]=max(ans[depth],root->val);
    DFS(root->left,depth+1);
    DFS(root->right,depth+1);
}
    vector<int> largestValues(TreeNode* root) {
        DFS(root,0);
        return ans;
    }
};