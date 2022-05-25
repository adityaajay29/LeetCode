class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = INT_MAX;
        int profit = 0;
        for(int i=0;i<n;i++)
        {
            cost = min(cost, prices[i]);
            profit = max(profit, prices[i]-cost);
        }
        return profit;
    }
};