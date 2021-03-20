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
    ListNode* swapPairs(ListNode* head) {
        ListNode* head_Copy = head;
        
        
        if(head==NULL)
           return NULL;
        if(head->next==NULL)
        {
            return head;
        }
        while(head->next!=NULL)
        {
            int a = head->val;
            head->val = head->next->val;
            head->next->val = a;
            head = head->next->next;
            if(head==NULL || head->next==NULL)
                break;
        }
        return head_Copy;
    }
};