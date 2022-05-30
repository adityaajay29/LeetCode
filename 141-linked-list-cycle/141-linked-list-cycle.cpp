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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;
        ListNode *dummy = new ListNode(0);
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        dummy->next = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            if(slow != dummy && slow == fast)
                    return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};