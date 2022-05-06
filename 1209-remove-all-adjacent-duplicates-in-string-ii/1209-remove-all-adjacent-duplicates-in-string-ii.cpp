class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char, int>> st;
        st.push({s[0],1});
        for(int i=1;i<n;i++)
        {
            if(st.empty() || st.top().first != s[i])
            {
                st.push({s[i],1});
            }
            else 
            {
                int topN=st.top().second;
                st.pop();
                st.push({s[i],topN+1});
            }
            if(st.top().second == k)
                st.pop();
        }
        string ans;
        while(!st.empty())
        {
            char topC=st.top().first;
            int topN=st.top().second;
            st.pop();
            while(topN--)
            {
                ans.push_back(topC);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};