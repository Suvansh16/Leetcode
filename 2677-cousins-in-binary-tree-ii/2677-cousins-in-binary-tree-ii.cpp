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
        //step1 store sum of each level
    vector<int>levelsum;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        int sum=0;

        while(n--)
        {
            TreeNode*a=q.front();
            q.pop();
            sum+=a->val;
            if(a->left)
            q.push(a->left);
            if(a->right)
            q.push(a->right);

        }
        levelsum.push_back(sum);
    }
    //step 2 subtract node val with levelsum-sibling sum
    int i=1;
    q.push(root);
    root->val=0;
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            TreeNode*a=q.front();
            q.pop();
            int siblingsum=0;
            if(a->left)
            {
                siblingsum+=a->left->val;
            }
            if(a->right)
            siblingsum+=a->right->val;
            if(a->left){
            a->left->val=levelsum[i]-siblingsum;
            q.push(a->left);
            }
            if(a->right){
            a->right->val=levelsum[i]-siblingsum;
            q.push(a->right);
            }


        }
        i++;
    }
    return root;
    }
};