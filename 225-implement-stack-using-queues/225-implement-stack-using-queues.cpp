class MyStack {
public:
    queue<int> q;
    
    void reverse()
    {
        if(q.size()==0)
            return;
        int temp=q.front();
        q.pop();
        reverse();
        q.push(temp);
    }
    
    MyStack() {
        
    }
    
    void push(int x) {
        reverse();
        q.push(x);
        reverse();
    }
    
    int pop() {
        int temp=q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */