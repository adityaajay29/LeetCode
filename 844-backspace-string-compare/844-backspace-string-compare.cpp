class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();
        int count=0;
        string a,b;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='#')
            {
                if(count>0)
                    count--;
                else 
                    a.push_back(s[i]);
            }
            else 
            {
                count++;
            }
        }
        count=0;
        for(int i=m-1;i>=0;i--)
        {
            if(t[i]!='#')
            {
                if(count>0)
                    count--;
                else 
                    b.push_back(t[i]);
            }
            else 
            {
                count++;
            }
        }
        return a==b;
    }
};