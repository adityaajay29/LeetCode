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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *before = new ListNode(0);
        ListNode *after = new ListNode(0);
        ListNode *temp1 = before, *temp2 = after;
        ListNode *curr = head;
        while(curr)
        {
            ListNode *next = curr->next;
            if(curr->val < x)
            {
                temp1->next = curr;
                curr->next = nullptr;
                temp1 = temp1->next;
            }
            else
            {
                temp2->next = curr;
                curr->next = nullptr;
                temp2 = temp2->next;
            }
            curr = next;
        }
        if(after->next != nullptr)
        {
            temp1->next = after->next;
        }
        return before->next;
    }
};