class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        int a,b;
        for(auto x:ops)
        {
            if(x=="C")
                s.pop();
            else if(x=="D")
                s.push(2*s.top());
            else if(x=="+")
            {
                a=s.top();
                s.pop();
                b=s.top();
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