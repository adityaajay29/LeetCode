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
        
        int l = 1;
        int h = n;
        
        while(l <= h)
        {
            if(mat[l][h] == 1)
                l++;
            else
                h--;
        }
        
        int candi = l;
        
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