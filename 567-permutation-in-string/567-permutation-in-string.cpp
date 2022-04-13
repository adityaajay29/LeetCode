class Solution {
public:
    
    bool areSame(vector<int>&v1,vector<int>&v2)
    {
        for(int i=0;i<256;i++)
        {
            if(v1[i]!=v2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(s1==s2)
            return true;
        if(n1>n2)
            return false;
        vector<int>v1(256,0);
        vector<int>v2(256,0);
        for(int i=0;i<s1.size();i++)
        {
            v1[s1[i]]++;
            v2[s2[i]]++;
        }
        for(int i=n1;i<n2;i++)
        {
            if(areSame(v1,v2))
                return true;
            else
            {
                v2[s2[i]]++;
                v2[s2[i-n1]]--;
            }
        }
        return (areSame(v1,v2));
    }
};