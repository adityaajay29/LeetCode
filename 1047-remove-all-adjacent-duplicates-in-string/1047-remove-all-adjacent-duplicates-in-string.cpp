class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for(char c : s)
        {
            if(!stack.empty() && stack.top() == c)
                stack.pop();
            else
                stack.push(c);
        }
        string ans = "";
        while(!stack.empty())
        {
            ans += stack.top();
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};