class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        priority_queue<int> neg;
        priority_queue<int, vector<int>, greater<int>> pos;
        
        for(int x : nums)
        {
            if(x < 0)
                neg.push(x);
            else
                pos.push(x);
        }
        if(neg.empty())
            return pos.top();
        
        if(pos.empty())
            return neg.top();
        
        int a = neg.top();
        int b = pos.top();
        
        return (abs(a) < b ? a : b);
    }
};