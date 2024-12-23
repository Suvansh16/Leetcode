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
int selection(vector<int>&ans)
{
    int count=0;
    int n=ans.size();
    int i=0;
    while(i<n)
    {
        int mini=ans[i];
        int ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(ans[j]<mini)
            {
                ind=j;
                mini=ans[j];
            }
        }
        if(ind!=i){
        swap(ans[i],ans[ind]);
        count++;
        }
        i++;
    }
    return count;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>ans;
            while(size--)
            {
                TreeNode*a=q.front();
                q.pop();
                if(a->left)
                q.push(a->left);
                if(a->right)
                q.push(a->right);
                ans.push_back(a->val);

            }
            count+=selection(ans);
        }
        return count;
    }
};