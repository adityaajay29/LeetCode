/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                Node *curr = q.front().first;
                int lvl = q.front().second;
                q.pop();
                if(!q.empty())
                {
                    if(q.front().second == lvl)
                    {
                        curr->next = q.front().first;
                    }
                }
                if(curr->left)
                    q.push({curr->left, lvl + 1});
                if(curr->right)
                    q.push({curr->right, lvl + 1});
            }
        }
        return root;
    }
};