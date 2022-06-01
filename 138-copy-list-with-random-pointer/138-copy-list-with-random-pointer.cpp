/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
//         inserting the node's copies next to nodes
        Node *curr = head;
        Node *front = head;
        while(curr)
        {
            front = curr->next;
            Node *copy = new Node(curr->val);
            copy->next = front;
            curr->next = copy;
            curr = front;
        }
        
//         assigning the random pointers to the copies
        curr = head;
        while(curr)
        {
            if(curr->random != nullptr)
            curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
//         segregating them
        curr = head;
        Node *dummy = new Node(0);
        Node *temp = dummy;
        while(curr)
        {
            front = curr->next->next;
            temp->next = curr->next;
            curr->next = front;
            temp = temp->next;
            curr = front;
        }
        return dummy->next;
    }
};