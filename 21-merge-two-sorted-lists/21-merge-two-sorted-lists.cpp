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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        
        if(list2 == nullptr)
            return list1;
        
        ListNode *newHead = new ListNode;
        ListNode *temp = new ListNode;
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        
        if(curr1->val <= curr2->val)
        {
            newHead->val = curr1->val;
            temp = newHead;
            curr1 = curr1->next;
        }
        else
        {
            newHead->val = curr2->val;
            temp = newHead;
            curr2 = curr2->next;
        }
        
        while(curr1 != nullptr && curr2 != nullptr)
        {
            ListNode *next = new ListNode;
            if(curr1->val <= curr2->val)
            {
                next->val = curr1->val;
                temp->next = next;
                temp = temp->next;
                curr1 = curr1->next;
            }
            else
            {
                next->val = curr2->val;
                temp->next = next;
                temp = temp->next;
                curr2 = curr2->next;
            }
        }
        while(curr1 != nullptr)
        {
            ListNode *next = new ListNode;
            next->val = curr1->val;
            temp->next = next;
            temp = temp->next;
            curr1 = curr1->next;
        }
        while(curr2 != nullptr)
        {
            ListNode *next = new ListNode;
            next->val = curr2->val;
            temp->next = next;
            temp = temp->next;
            curr2 = curr2->next;
        }
        return newHead;
    }
};