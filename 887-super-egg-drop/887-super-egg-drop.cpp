class Solution {
public:
    int dp[101][10001];
    
    int solver(int k, int n)
    {
        //  base case 1
        if(n == 0 || n == 1)
            return n;
        
        //  base case 2 (in worst case)
        if(k == 1)
            return n;
        
        if(dp[k][n] != -1)
            return dp[k][n];
        
        int attempts = INT_MAX;
        
        //  possible candidates of f
//         using binary Search 
        int l=1;
        int h=n;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int breaks = solver(k-1, mid-1);
            int notBreaks = solver(k, n-mid);
            int worstCase = 1 + max(breaks, notBreaks);
            if(breaks < notBreaks)
//                 to get min attempts in worst case, we goto above floors
                l = mid + 1;
            else
//                 to goto min attempts in worst case, we goto lower floors
                h = mid - 1;
            attempts = min(attempts, worstCase);
        }
        return dp[k][n] = attempts;
    }
    
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solver(k, n);
    }
};