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
        ListNode *curr=head;
        if(head->next==NULL && n==1)
            return NULL;
        int sz=0;
        while(curr)
        {
            sz++;
            curr=curr->next;
        }
        curr=head;
        if(sz-n==0)
        {
            ListNode *temp=head->next;
            delete head;
            return temp;
        }
        int i=1;
        while(curr->next && i<sz-n)
        {
            curr=curr->next;
            i++;
        }
        ListNode *temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
        return head;
    }
};