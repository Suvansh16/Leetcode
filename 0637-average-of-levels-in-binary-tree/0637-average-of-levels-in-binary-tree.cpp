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

void solve(vector<double>&ans,TreeNode*root)
{
   queue<TreeNode*>q;
   q.push(root);
   while(!q.empty())
   {
    int size=q.size();
    int l=size;
    double avg=0;
    while(size--)
    {
        avg+=q.front()->val;
        TreeNode*top=q.front();
        q.pop();
        if(top->left)
        q.push(top->left);
        if(top->right)
        q.push(top->right);
    }
    avg=avg/l;
    ans.push_back(avg);
   }
}
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL)
        return {} ;
        vector<double>ans;
        solve(ans,root);
        return ans;
    }
};