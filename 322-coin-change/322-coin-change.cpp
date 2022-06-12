class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev (amount + 1, 0);
//         base case
        for(int j=0;j<=amount;j++)
        {
            if(j % coins[0] == 0)
                prev[j] = j / coins[0];
            else prev[j] = INT_MAX - 1;
        }
        
        for(int i=1;i<n;i++)
        {
            vector<int> curr(amount + 1, 0);
            for(int j=0;j<=amount;j++)
            {
                int take = INT_MAX - 1;
                int notTake = prev[j];
                if(coins[i] <= j)
                    take = 1 + curr[j - coins[i]];
                curr[j] = min(take, notTake);
            }
            prev = curr;
        }
        return (prev[amount] == INT_MAX - 1 ? -1 : prev[amount]);
    }
};