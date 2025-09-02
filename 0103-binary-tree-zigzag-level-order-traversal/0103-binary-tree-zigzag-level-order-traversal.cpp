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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int t=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>v;
            while(size)
            {
                TreeNode*rop=q.front();
                q.pop();
               v.push_back(rop->val);
               if(rop->left)
               q.push(rop->left);
               if(rop->right)
               q.push(rop->right);
               size--;
            }
            if(t%2==0)
            ans.push_back(v);
            else
            {
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            t++;
        }
        return ans;
    }
};