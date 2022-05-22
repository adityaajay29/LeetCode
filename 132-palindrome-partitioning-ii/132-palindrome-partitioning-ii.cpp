class Solution {
public:
    
    int dp[2001][2001];
    
    bool isPalindrome(string &s, int i, int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j)
    {
        if(i >= j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(isPalindrome(s, i, j))
            return 0;
        
        int ans = INT_MAX;
        int left, right;
        
        for(int k=i;k<j;k++)
        {
//          if the left part is already a palindrome, then no need to solve for it, 
//          just add 1 to solve for right
            if(isPalindrome(s, i, k))
            {
                ans = min(ans, 1 + solve(s, k+1, j));
            }
        }
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n=s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n-1);
    }
};