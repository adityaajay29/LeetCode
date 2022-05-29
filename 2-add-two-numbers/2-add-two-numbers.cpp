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
        ListNode *a = l1;
        ListNode *b = l2;
        ListNode *head = new ListNode(0);
        int carry = 0;
        ListNode *temp = head;
        while(a || b)
        {
            ListNode *next = new ListNode;
            int sum = 0;
            if(a && b)
                sum = a->val + b->val + carry;
            else if(a)
                sum = a->val + carry;
            else if(b)
                sum = b->val + carry;
            if(sum <= 9)
            {
                next->val = sum;
                temp->next = next;
                temp = temp->next;
                carry = 0;
            }
            else
            {
                sum %= 10;
                next->val = sum;
                temp->next = next;
                temp = temp->next;
                carry = 1;
            }
            if(a)
            a = a->next;
            if(b)
            b = b->next;
        }
        if(carry == 1)
            temp->next = new ListNode(1);
        return head->next;
    }
};