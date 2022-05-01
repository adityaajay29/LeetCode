class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        int countS=0;
        int countT=0;
        while(i>=0 || j>=0)
        {
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    countS++;
                    i--;
                }
                else if(countS>0)
                {
                    countS--;
                    i--;
                }
                else 
                    break;
            }
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    countT++;
                    j--;
                }
                else if(countT>0)
                {
                    countT--;
                    j--;
                }
                else 
                    break;
            }
            if(i>=0 && j>=0 && s[i]!=t[j])
                return false;
            if((i>=0) != (j>=0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};