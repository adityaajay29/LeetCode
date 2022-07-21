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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = nullptr, *curr = dummy;
        int i = 0;
        while(i < left)
        {
            prev = curr;
            curr = curr->next;
            i++;
        }
        int rev = (right - left);
        ListNode *next = curr->next;
        while(rev > 0)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
            rev--;
        }
        return dummy->next;
    }
};