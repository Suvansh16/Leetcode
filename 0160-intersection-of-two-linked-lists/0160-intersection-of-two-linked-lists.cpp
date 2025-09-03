/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *temp=headA;
           ListNode *second=headB;
           int len1=0;
           int len2=0;
     while(temp!=NULL)
     {
      len1++;
      temp=temp->next;
     }
       while(second!=NULL)
     {
     len2++;
     second=second->next;
     }
     if(len1>len2)
     {
         while(len1!=len2)
         {
             headA=headA->next;
             len1--;

         }
     }
     if(len2>len1)
     {
         while(len1!=len2)
         {
             headB=headB->next;
             len2--;

         }
     }
     while(headA!=NULL && headB!=NULL)
     {
         if(headA==headB)
         {
             return headA;
         }
         headA=headA->next;
         headB=headB->next;
     }
     return NULL;
    }
     
};