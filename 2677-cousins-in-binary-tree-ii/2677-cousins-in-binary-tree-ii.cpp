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
    TreeNode* replaceValueInTree(TreeNode* root) {
       if(root==NULL)
       return NULL;
       queue<TreeNode*>q;
       int levelsum=root->val;
       q.push(root);
       
       while(!q.empty())
       {
        int nextlevelsum=0;
        int n=q.size();
        while(n--)
        {
            TreeNode*curr=q.front();
            q.pop();
            curr->val=levelsum-curr->val;
            int siblingsum=(curr->left!=NULL?curr->left->val:0);
            siblingsum+=(curr->right!=NULL?curr->right->val:0);
            if(curr->left)
            {
                nextlevelsum+=curr->left->val;
                curr->left->val=siblingsum;
                q.push(curr->left);
            }
            if(curr->right)
            {
                nextlevelsum+=curr->right->val;
                curr->right->val=siblingsum;
                q.push(curr->right);
            }

        }
        levelsum=nextlevelsum;
       }
       return root;
    }
};