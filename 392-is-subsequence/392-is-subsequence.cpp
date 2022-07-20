class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0)
        {
            if(s[i] == t[j])
            {
                i--;
                j--;
            }
            else 
                j--;
        }
        return i == -1;
    }
};