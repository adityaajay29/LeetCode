class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cost = INT_MAX;
        for(int x : prices)
        {
            cost = min(cost, x);
            profit = max(profit, x - cost);
        }
        return profit;
    }
};