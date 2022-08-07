class node
{
    public:
    node *links[26];
    bool flag = false;
    
    bool containsKey(char c)
    {
        return (links[c - 'a'] != nullptr);
    }
    
    void put(char c, node *temp)
    {
        links[c - 'a'] = temp;
    }
    
    node *get(char c)
    {
        return links[c - 'a'];
    }
    
    void setEnd()
    {
       flag = true; 
    }
    
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private : 
    node *root;
    
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node *curr = root;
        for(int i=0;i<word.size();i++)
        {
            if(!curr->containsKey(word[i]))
            {
                curr->put(word[i], new node());
            }
            curr = curr->get(word[i]);
        }
        curr->setEnd();
    }
    
    bool search(string word) {
        node *curr = root;
        for(int i=0;i<word.size();i++)
        {
            if(!curr->containsKey(word[i]))
            {
                return false;
            }
            curr = curr->get(word[i]);
        }
        return curr->isEnd();
    }
    
    bool startsWith(string prefix) {
        node *curr = root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!curr->containsKey(prefix[i]))
            {
                return false;
            }
            curr = curr->get(prefix[i]); 
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