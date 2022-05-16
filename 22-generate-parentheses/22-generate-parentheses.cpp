class Solution {
public:
    
    void helper(int open, int close, string temp, vector<string> &ans)
    {
        if(!open && !close)
        {
            ans.push_back(temp);
            return;
        }
        if(open)
        {
            string ans1=temp;
            ans1.push_back('(');
            helper(open-1, close, ans1, ans);
        }
        if(close>open)
        {
            string ans2=temp;
            ans2.push_back(')');
            helper(open, close-1, ans2, ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, n, "", ans);
        for(auto s:ans)
            cout<<s<<" ";
        return ans;
    }
};