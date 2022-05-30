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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = dummy;
        ListNode *next = dummy;
        int sz = 0;
        curr = head;
        while(curr)
        {
            sz++;
            curr = curr->next;
        }
        while(sz >= k)
        { 
            curr = prev->next;
            next = curr->next;
//             swapping individual nodes of each group
//             if group size is k, there will be k-1 reversals in that group
            for(int i=1;i<k;i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            sz -= k;
        }
        return dummy->next;
    }
};