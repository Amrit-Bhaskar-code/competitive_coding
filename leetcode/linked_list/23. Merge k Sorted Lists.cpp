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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        while(lists.size()>1)
        {
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* a, ListNode* b)
    {
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a->val<b->val)
        {
            a->next = merge2Lists(a->next, b);
            return a;
        }
        else
        {
            b->next = merge2Lists(a, b->next);
            return b;
        }
    }
    
    
    
};