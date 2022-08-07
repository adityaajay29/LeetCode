struct node
{
    node *arr[26];
    bool end;
    
    node()
    {
        end = false;
        for(int i=0;i<26;i++)
        {
            arr[i] = nullptr;
        }
    }
    
    bool contains(char c)
    {
        return (arr[c - 'a'] != nullptr);
    }
};

class Trie {
private:
    node *root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                curr->arr[c - 'a'] = new node();
            curr = curr->arr[c - 'a'];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                return false;
            
            curr = curr->arr[c - 'a'];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        node *curr = root;
        for(char c : prefix)
        {
            if(!curr->contains(c))
                return false;
            
            curr = curr->arr[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */