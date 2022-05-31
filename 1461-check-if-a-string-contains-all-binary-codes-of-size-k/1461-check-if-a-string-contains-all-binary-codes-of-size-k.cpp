class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size())
            return false;
        
        unordered_set<string> set;
        string temp;
        for(int i=0;i<k;i++)
        {
            temp.push_back(s[i]);
        }
        set.insert(temp);
        for(int i=k;i<s.size();i++)
        {
            temp.erase(temp.begin());
            temp.push_back(s[i]);
            if(set.find(temp) == set.end())
                set.insert(temp);
        }
        return set.size() == pow(2, k);
    }
};