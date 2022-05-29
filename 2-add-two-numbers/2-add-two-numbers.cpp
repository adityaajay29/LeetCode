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
        
        while(a != nullptr || b != nullptr)
        {
            ListNode *next = new ListNode;
            int sum = 0;
            
            if(a != nullptr)
                sum += a->val;
            if(b != nullptr)
                sum += b->val;
            sum += carry;
            
            if(sum <= 9)
            {
                carry = 0;
            }
            else
            {
                sum %= 10;
                carry = 1;
            }
            
            next->val = sum;
            temp->next = next;
            temp = temp->next;
            
            if(a != nullptr)
            a = a->next;
            
            if(b != nullptr)
            b = b->next;
        }
        
        if(carry == 1)
            temp->next = new ListNode(1);
        
        return head->next;
    }
};