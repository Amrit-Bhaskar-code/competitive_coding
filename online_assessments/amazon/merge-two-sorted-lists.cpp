// https://leetcode.com/problems/merge-two-sorted-lists/submissions/


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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
         ListNode *head,*prev,*temp;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val < l2->val)
        {
            temp = new ListNode();
            temp->val = l1->val;
            temp->next=NULL;
            l1 = l1->next;
        }
        else
        {
            temp = new ListNode();
            temp->val = l2->val;
            temp->next=NULL;
            l2 = l2->next;
        }
        head = temp;
        prev = temp;
        
        while(l1!=NULL && l2!=NULL)
        {
            
                if(l1->val < l2->val)
                {
                    temp = new ListNode();
                    temp->val = l1->val;
                    temp->next=NULL;
                    l1 = l1->next;
                }
                else
                {
                    temp = new ListNode();
                    temp->val = l2->val;
                    temp->next=NULL;
                    l2 = l2->next;
                }
            prev->next = temp;
            prev=temp;
        }
        
        if(l1)
            prev->next = l1;
        if(l2)
            prev->next = l2;
        
        
        return head;
        
    }
};
