/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        
        string serial = "";
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if(curr == nullptr)
                serial.append("#,");
            else
            {
                serial.append(to_string(curr->val) + ',');
            }
            if(curr != nullptr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        // cout<<serial;
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return nullptr;
        
        stringstream s(data);
        string temp;
//         creating root of the tree
        getline(s, temp, ',');
        TreeNode *root = new TreeNode(stoi(temp));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
//             making left connection
            getline(s, temp, ',');
            if(temp == "#")
                curr->left = nullptr;
            else
            {
                TreeNode *left = new TreeNode(stoi(temp));
                curr->left = left;
                q.push(left);
            }
//             making right connection
            getline(s, temp, ',');
            if(temp == "#")
                curr->right = nullptr;
            else
            {
                TreeNode *right = new TreeNode(stoi(temp));
                curr->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));