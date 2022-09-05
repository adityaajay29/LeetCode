/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            while(sz--)
            {
                Node *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                for(Node *child : curr->children)
                    q.push(child);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};