class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == ' ')
                continue;
            string temp;
            while(i >= 0 && s[i] != ' ')
            {
                temp.push_back(s[i]);
                i--;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += " ";
        }
        if(ans.back() == ' ')
            ans.pop_back();
        
       return ans;
    }
};