class Solution {
public:
    
    int subsetSum(vector<int> &nums, int n, int sum, int count0)
    {
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(!i)
                    dp[i][j]=0;
                if(!j)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1] <= j && nums[i-1] != 0)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return pow(2, count0)*dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int range=0;
//         count of 0 to handle the tc with multiple 0s
//         ex : [0,0,0,0,0,0,0,0,1]
//                 1
//         op : 256, not 1
        int count0=0;
        for(int x : nums)
        {
            range+=x;
            if(x == 0)
                count0++;
        }
//         if the sum is odd, then no combination possible
        if((range + target)%2 || range < abs(target))
            return 0;
        int sum = (range + target)/2;
        return subsetSum(nums, n, sum, count0);
    }
};