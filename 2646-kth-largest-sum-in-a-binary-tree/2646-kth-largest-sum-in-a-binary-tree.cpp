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
    long long kthLargestLevelSum(TreeNode* root, int k) {
       priority_queue<long long>pq;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            long long sum=0;
            while(size--)
            {
                TreeNode*val1=q.front();
                q.pop();
                sum+=val1->val;
                if(val1->left)
                q.push(val1->left);
                if(val1->right)
                q.push(val1->right);
            }
            pq.push(sum);
        }
        if(pq.size()<k)
        return -1;
        k-=1;
        while(k--)
        {
            pq.pop();
        }
        return pq.top();
    }
};