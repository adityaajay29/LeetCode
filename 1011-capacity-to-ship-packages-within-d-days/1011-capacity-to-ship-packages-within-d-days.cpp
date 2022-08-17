class Solution {
public:
    bool isPossible(vector<int> &arr, int maxWt, int maxDays)
    {
        int currWt = 0;
        int days = 1;
        for(int i=0;i<arr.size();i++)
        {
            if(currWt + arr[i] > maxWt)
            {
                days++;
                currWt = arr[i];
                if(currWt > maxWt)
                    return false;
            }
            else
                currWt += arr[i];
        }
        return days <= maxDays;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, h = 0;
        for(int x : weights)
        {
            l = min(l, x);
            h += x;
        }
        int ans = 0;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(isPossible(weights, mid, days))
            {
                ans = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};