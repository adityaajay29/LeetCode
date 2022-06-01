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
    void reverse(ListNode *curr, ListNode *prev, ListNode *next, int end)
    {
        for(int i=1;i<end;i++)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = dummy;
        ListNode *next = dummy;
        
        curr = head;
        int sz = 0;
        while(curr)
        {
            sz++;
            curr = curr->next;
        }
        
        k %= sz;
        
        if(k == 0)
            return head;
        
        curr = prev->next;
        next = curr->next;
        reverse(curr, prev, next, sz-k);
        
        prev = curr;
        curr = prev->next;
        next = curr->next;
        reverse(curr, prev, next, k);
        
        prev = nullptr;
        curr = dummy->next;
        while(curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};