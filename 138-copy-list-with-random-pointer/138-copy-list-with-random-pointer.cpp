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
        if(head == nullptr)
            return nullptr;
        
        unordered_map<Node *, Node *> mp;
        Node *curr = head;
        while(curr != nullptr)
        {
            Node *copy = new Node(curr->val);
            mp[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr != nullptr)
        {
            Node *currNext = curr->next;
            Node *currRand = curr->random;
            mp[curr]->next = mp[currNext];
            mp[curr]->random = mp[currRand];
            curr = curr->next;
        }
        return mp[head];
    }
};