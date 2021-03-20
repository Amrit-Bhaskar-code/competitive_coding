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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
        {
            return NULL;
        }
        
        ListNode *start = head;
        while(n--)
        {
            start = start->next;
        }
                
        ListNode *temp = head;
        while(start!=NULL)
        {
            temp = temp->next;
            start=start->next;
        }        
        ListNode *new_head = head;
        if(head==temp)
        {
            return head->next;
        }
        while(head->next!=NULL)
        {
            if(head->next==temp)
            {
                head->next = head->next->next;
                break;
            }
            head = head->next;
        }
        return new_head;  
    }
};