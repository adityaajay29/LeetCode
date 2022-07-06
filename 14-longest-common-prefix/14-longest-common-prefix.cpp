class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string first = strs[0];
        
        for(int i=0;i<first.size();i++)
        {
            char curr = first[i];
            for(int j=1;j<n;j++)
            {
                string temp = strs[j];
                if(temp[i] != curr || i == temp.size())
                    return first.substr(0, i);
            }
        }
        return first;
    }
};