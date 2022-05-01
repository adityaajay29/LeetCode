class Solution {
public:
    bool backspaceCompare(string s, string t) {
        if(s==t)
            return true;
        int n=s.size();
        int m=t.size();
//         count the backspaces
        int count=0;
        string a,b;
//         start from last char
        for(int i=n-1;i>=0;i--)
        {
//             if s[i] isn't a backspace, check if there were previous backspaces or not
            if(s[i]!='#')
            {
//                 if there were backspaces, then skip that char and decrease the count 
                if(count>0)
                    count--;
                else 
//                     if there were no backspaces, push that char to string, as it will not be erased
                    a.push_back(s[i]);
            }
//             if char is a backspace, then increase its count
            else 
            {
                count++;
            }
        }
//         check the same for 2nd string
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
//         return true if both the strings a,b are same at last
        return a==b;
    }
};