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
        
        ListNode *small = list1, *large = list2;
        if(large->val < small->val)
            swap(small, large);
        
        ListNode *head = small;
        
        while(small && large)
        {
            ListNode *temp = nullptr;
            while(small && small->val <= large->val)
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