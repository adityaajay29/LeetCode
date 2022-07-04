class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> mat(n + 1, vector<int> (n + 1, 0));
        
        for(int i=0;i<trust.size();i++)
        {
            
            int a = trust[i][0];
            int b = trust[i][1];
            mat[a][b] = 1;
        }
        
        stack<int> s;
        for(int i=1;i<=n;i++)
        {
            s.push(i);
        }
        
        while(s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(mat[a][b] == 1)
                s.push(b);
            else
                s.push(a);
        }
        int candi = s.top();
        s.pop();
        
        for(int i=1;i<=n;i++)
        {
            if(i != candi)
            {
                if(mat[i][candi] == 0 || mat[candi][i] == 1)
                    return -1;
            }
        }
        return candi;
    }
};