class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        if(s.size() == 0)
            return 0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.size();i++)
        {
//             if opening bracket, push it
            if(s[i] == '(')
            st.push(i);
//             if closing then check whether top is opening or not
            else if(s[i] == ')')
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};