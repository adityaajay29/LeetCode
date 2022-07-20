class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> list[26];
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            list[c - 'a'].push_back(i);
        }
        int count = 0;
        for(string &word : words)
        {
            int i = -1;
            bool found = true;
            for(char c : word)
            {
                auto it = upper_bound(list[c - 'a'].begin(), list[c - 'a'].end(), i);
                if(it == list[c - 'a'].end())
                {
                    found = false;
                    break;
                }
                else 
                    i = *it;
            }
            if(found)
                count++;
        }
        return count;
    }
};