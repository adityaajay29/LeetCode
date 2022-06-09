class Solution {
public:
    bool isValidShip(int maxWeight, vector<int> &wt, int maxDays)
    {
        int weight = 0;
        int days = 1;
        for(int i=0;i<wt.size();i++)
        {
            if(weight + wt[i] > maxWeight)
            {
                days++;
                weight = wt[i];
                if(weight > maxWeight)
                    return false;
            }
            else
                weight += wt[i];
        }
        return (days > maxDays ? false : true);
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(days > n)
            return -1;
        
        int l = 0;
        for(int x : weights)
            l = max(l, x);
        
        int h = weights[0];
        for(int i=1;i<n;i++)
        {
            h += weights[i];
        }
        
        int ans = -1;
        
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(isValidShip(mid, weights, days))
            {
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};