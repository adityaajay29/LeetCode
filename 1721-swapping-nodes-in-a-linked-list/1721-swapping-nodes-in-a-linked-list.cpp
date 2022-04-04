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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return head;
        
        ListNode *curr=head;
//         finding the length of ll
        int n=1;
        while(curr->next)
        {
            n++;
            curr=curr->next;
        }
        // cout<<n<<endl;
        curr=head;
        int i=1;
        while(curr->next!=NULL && i<k)
        {
            curr=curr->next;
            i++;
        }
        int temp1=curr->val;
        // cout<<temp1<<endl;
        
        curr=head;
        int j=1;
        while(curr->next && j<=n-k)
        {
            curr=curr->next;
            j++;
        }
        int temp2=curr->val;
        // cout<<temp2<<endl;
        
        curr=head;
        int l=1;
        while(curr->next && l<k)
        {
            curr=curr->next;
            l++;
        }
        curr->val=temp2;
        
        curr=head;
        int h=1;
        while(curr->next && h<=n-k)
        {
            curr=curr->next;
            h++;
        }
        curr->val=temp1;
        
        // cout<<temp<<endl;
        
//         while(i<=n-k && curr->next!=NULL)
//         {
//             curr=curr->next;
//             i++;
//         }
        
//         int store=curr->val;
//         // cout<<store;
//         curr->val=temp;
//         curr=head;
//         int j=1;
        
//         while(curr->next && j<k)
//         {
//             curr=curr->next;
//             j++;
//         }
//         curr->val=store;
        return head;
        
    }
};