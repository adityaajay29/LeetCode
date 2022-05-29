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
//         assuming list1->val is smaller
        ListNode *small = list1;
        ListNode *large = list2;
//         assigning small to whichever is smaller
        if(list1->val > list2->val)
            swap(small, large);
        ListNode *head = small;
        while(small != nullptr && large != nullptr)
        {
            ListNode *temp = nullptr;
            while(small != nullptr && small->val <= large->val)
            {
                temp = small;
                small = small->next;
            }
            temp->next = large;
            swap(small, large);
        }
        return head;
    }
};