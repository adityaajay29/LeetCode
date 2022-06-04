class Solution {
public:
    bool isPalindrome(string str, int l, int h)
    {
        while(l<h)
        {
            if(str[l] != str[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
    
    void solve(string s, vector<vector<string>> &ans, vector<string> temp, int i)
    {
        if(i == s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int j=i;j<s.size();j++)
        {
            if(isPalindrome(s, i, j))
            {
                temp.push_back(s.substr(i, j-i+1));
                solve(s, ans, temp, j+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        solve(s, ans, {}, 0);
        return ans;
    }
};