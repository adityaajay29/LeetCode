class MedianFinder {
public:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(low.empty() || num < low.top())
            low.push(num);
        else
            high.push(num);
        int n1 = low.size();
        int n2 = high.size();
        if(n1 - n2 > 1)
        {
            high.push(low.top());
            low.pop();
        }
        else if(n2 - n1 > 1)
        {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if(low.size() == high.size())
        {
            return (low.top() + high.top())/2.0;
        }
        else
            return (low.size() > high.size() ? low.top() : high.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */