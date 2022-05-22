class Solution {
public:
    
    bool isPalindrome(string &s, int i, int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string &s, vector<vector<string>> &ans, vector<string> &temp, int i)
    {
        if(i >= s.size())
        {
            ans.push_back(temp);
        }
        for(int k=i;k<s.size();k++)
        {
            if(isPalindrome(s, i, k))
            {
                temp.push_back(s.substr(i, k-i+1));
                solve(s, ans, temp, k+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, ans, temp, 0);
        return ans;
    }
};