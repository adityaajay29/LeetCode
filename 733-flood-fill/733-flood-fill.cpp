class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, -1, 1};
    
    bool isValid(vector<vector<int>>& image, vector<vector<int>> &visited, int i,int j, int sr, int sc, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        if(visited[i][j] || image[i][j] != image[sr][sc])
            return false;
        
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n= image[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        queue<pair<int,int>> q;
        visited[sr][sc] = 1;
        q.push({sr, sc});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(isValid(image, visited, x + dx[i], y + dy[i], sr, sc, m, n))
                {
                    visited[x + dx[i]][y + dy[i]] = 1;
                    q.push({x + dx[i], y + dy[i]});
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j] == 1)
                    image[i][j] = color;
            }
        }
        return image;
    }
};