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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        int sz = 0;
        while(curr)
        {
            sz++;
            curr = curr->next;
        }
        curr = head;
        ListNode *temp = new ListNode;
        if(sz-n == 0)
        {
            temp = head->next;
            delete head;
            return temp;
        }
        int i = 1;
        while(curr->next && i < sz-n)
        {
            i++;
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
};