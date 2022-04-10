class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(auto x:ops)
        {
            if(x=="C")
                s.pop();
            else if(x=="D")
                s.push(2*s.top());
            else if(x=="+")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.push(a);
                s.push(a+b);
            }
            else 
                s.push(stoi(x));
        }
        int ans=0;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};