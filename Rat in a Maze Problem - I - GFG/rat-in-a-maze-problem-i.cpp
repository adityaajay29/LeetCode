// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isValid(int i, int j,int n, vector<vector<int>> &m, vector<vector<int>> &visited)
    {
        if(i < 0 || i >= n || j < 0 || j >= n)
        return false;
        
        if(visited[i][j] == 1)
        return false;
        
        if(m[i][j] == 0)
        return false;
        
        return true;
    }
    
    void solve(vector<string> &ans, vector<vector<int>> &m, vector<vector<int>> &visited, string temp, int n, int i, int j)
    {
        if(i == n-1 && j == n-1)
        {
            ans.push_back(temp);
            return;
        }
        // down
        if(isValid(i + 1, j, n, m, visited))
        {
            visited[i][j] = 1;
            solve(ans, m, visited, temp + 'D', n, i + 1, j);
            visited[i][j] = 0;
        }
        // right
        if(isValid(i, j + 1, n, m, visited))
        {
            visited[i][j] = 1;
            solve(ans, m, visited, temp + 'R', n, i, j + 1);
            visited[i][j] = 0;
        }
        // up
        if(isValid(i - 1, j, n, m, visited))
        {
            visited[i][j] = 1;
            solve(ans, m, visited, temp + 'U', n, i - 1, j);
            visited[i][j] = 0;
        }
        // left
        if(isValid(i, j - 1, n, m, visited))
        {
            visited[i][j] = 1;
            solve(ans, m, visited, temp + 'L', n, i, j - 1);
            visited[i][j] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
        return {};
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int> (n, 0));
        solve(ans, m, visited, "", n, 0, 0);
        return ans;
    }
};
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends