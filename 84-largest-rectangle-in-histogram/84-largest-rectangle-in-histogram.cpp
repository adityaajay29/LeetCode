class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
//         stack for keeping track of indices of h
        stack<int> s;
        vector<int> rLimit(n, n-1);
        vector<int> lLimit(n, 0);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && h[s.top()] >= h[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                rLimit[i] = s.top() - 1;
            }
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && h[s.top()] >= h[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                lLimit[i] = s.top() + 1;
            }
            s.push(i);
            int temp = h[i] * (rLimit[i] - lLimit[i] + 1);
            ans = max(ans, temp);
        }
        // int i = 0;
        // int ans = 0;
        // while(i < n)
        // {
        //     int temp = h[i] * (rLimit[i] - lLimit[i] + 1);
        //     ans = max(ans, temp);
        //     i++;
        // }
        return ans;
    }
};