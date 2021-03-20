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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode* head = l1;
        ListNode* prev= NULL;
        while(l1!=NULL && l2!=NULL)
        {
            sum += l1->val + l2->val;
            l1->val = sum%10;
            sum = sum/10;
            
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l2!=NULL)
        {
            ListNode* newnode = new ListNode;
            sum += l2->val;
            
            newnode->val = sum%10;
            newnode->next=NULL;
            
            prev->next = newnode;
            prev=newnode;
            sum = sum/10;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            
            sum += l1->val;
            
            l1->val = sum%10;
            sum = sum/10;
            prev = l1;
            l1=l1->next;
        }
        if(sum>0)
        {
           ListNode* newnode = new ListNode;
            newnode->val = sum;
            newnode->next=NULL;
            prev->next = newnode;
        }
        return head;
    }
};