class Solution {
public:
    void helper(vector<string> &ans, unordered_map<char, string> &mp, string &digits, int i, string temp)
    {
        if(i==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string s=mp[digits[i]];
        for(int j=0;j<s.size();j++)
        {
            helper(ans, mp, digits, i+1, temp+s[j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> ans;
        if(!digits.size())
            return ans;
        helper(ans, mp, digits, 0, "");
        return ans;
    }
};