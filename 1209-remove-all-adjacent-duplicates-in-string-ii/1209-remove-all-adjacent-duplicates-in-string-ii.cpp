class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char, int>> st;
        st.push({s[0],1});
        for(int i=1;i<n;i++)
        {
            if(!st.empty())
            {
                if(st.top().first == s[i])
                {
                    st.push({s[i],st.top().second+1});
                    if(st.top().second > k || st.top().second == k)
                    {
                        int count=k;
                        while(count && !s.empty())
                        {
                            st.pop();
                            count--;
                        }
                    }
                }
                else 
                    st.push({s[i],1});
            }
            else 
                st.push({s[i],1});
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};