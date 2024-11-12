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
TreeNode*solve(vector<int>&arr,int left,int right)
{
    if(left>right)
    return NULL;
    int mid=(left+right)/2;
    TreeNode*curr=new TreeNode(arr[mid]);
    if(left==right)
    return curr;
    curr->left=solve(arr,left,mid-1);
    curr->right=solve(arr,mid+1,right);
    return curr;
}
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head!=NULL)
        {
            arr.push_back(head->val);
            head=head->next;
        }
       
        int left=0;
        int right=arr.size();
        if(arr.size()==0)
        return NULL;
        return solve(arr,left,right-1);
    }
};