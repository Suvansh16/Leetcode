/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
ListNode*newhead;
bool solve(TreeNode* root,ListNode*head)
{
    if(head==NULL)
    return true;
    if(root==NULL)
    return false;
    if(root->val==head->val)
    {
        return solve(root->left,head->next) || solve(root->right,head->next);
    }
    return false;
}
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL)
        return false;
        return solve(root,head) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};