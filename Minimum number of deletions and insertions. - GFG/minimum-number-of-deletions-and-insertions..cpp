// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
	{
	    if(i == 0 || j == 0)
	    return 0;
	    
	    if(dp[i][j] != -1)
	    return dp[i][j];
	    
	    if(s1[i - 1] == s2[j - 1])
	    return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp);
	    
	    return dp[i][j] = max(solve(s1, s2, i - 1, j, dp), solve(s1, s2, i, j - 1, dp));
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    
	    vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
	    
	    int lcs = solve(str1, str2, m, n, dp);
	    
	    int del = m - lcs;
	    int ins = n - lcs;
	    return del + ins;
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends