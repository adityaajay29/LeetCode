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
        ListNode *slow, *fast;
        slow = fast = dummy;
        int i = 1;
        while(fast && i <= (right - left))
        {
            fast = fast->next;
            i++;
        }
        i = 1;
        while(fast && i < left)
        {
            slow = slow->next;
            fast = fast->next;
            i++;
        }
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        i = 0;
        while(i <= (right - left))
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        slow->next->next = curr;
        slow->next = prev;
        return dummy->next;
    }
};