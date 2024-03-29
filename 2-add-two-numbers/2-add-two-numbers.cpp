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
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while(l1 || l2)
        {
            int sum = 0;
            if(l1)
                sum += l1->val;
            if(l2)
                sum += l2->val;
            sum += carry;
            if(sum > 9)
            {
                sum %= 10;
                carry = 1;
            }
            else
                carry = 0;
            ListNode *node = new ListNode(sum);
            temp->next = node;
            temp = temp->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry == 1)
        {
            ListNode *node = new ListNode(carry);
            temp->next = node;
        }
        return dummy->next;
    }
};