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
        if(head == nullptr)
            return nullptr;
        
        vector<int> v;
        ListNode *curr = head;
        while(curr)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        for(int i=0;i<v.size();i+=k)
        {
            if(v.size()-i >= k)
            {
                reverse(v.begin()+i, v.begin()+i+k);
            }
        }
        int i=0;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while(i<v.size())
        {
            ListNode *next = new ListNode(v[i]);
            temp->next = next;
            temp = temp->next;
            i++;
        }
        return dummy->next;
    }
};