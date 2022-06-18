class LRUCache {
public:
    struct node
    {
        pair<int, int> val;
        node *next;
        node *prev;
        node(pair<int, int> x)
        {
            val = x;
            next = prev = nullptr;
        }
    };
    
    node *head = new node({0, 0});
    node *tail = new node({0, 0});
    
    int cap;
    unordered_map<int, node *> mp;
    
    void deleteNode(node *curr)
    {
        node *currPrev = curr->prev;
        node *currNext = curr->next;
        currPrev->next = currNext;
        currNext->prev = currPrev;
    }
    
    void addNode(node *temp)
    {
        node *headNext = head->next;
        temp->next = headNext;
        headNext->prev = temp;
        temp->prev = head;
        head->next = temp;
    }
        
    LRUCache(int capacity) {
        cap = capacity;
        tail->prev = head;
        head->next = tail;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        node *curr = mp[key];
        int value = curr->val.second;
        mp.erase(key);
        deleteNode(curr);
        addNode(curr);
        mp[key] = head->next;
        
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            node *temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size() == cap)
        {
            mp.erase(tail->prev->val.first);
            deleteNode(tail->prev);
        }
        node *newNode = new node({key, value});
        addNode(newNode);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */