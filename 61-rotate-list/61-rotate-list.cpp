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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        int sz = 1;
        ListNode *curr = head;
        while(curr->next != nullptr)
        {
            sz++;
            curr=curr->next;
        }
        curr->next = head;
        
        k %= sz;
        
        curr = head;
        
        int i = sz - k;
        while(i > 1)
        {
            curr = curr->next;
            i--;
        }
        ListNode *temp = curr->next;
        curr->next = nullptr;
        return temp;
    }
};