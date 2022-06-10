class Solution {
public:
    bool isDistanceValid(int minDist, vector<int> &posi, int maxBalls)
    {
        int balls = 1;
        int currPosi = posi[0];
        for(int i=1;i<posi.size();i++)
        {
            if(posi[i] - currPosi >= minDist)
            {
                balls++;
                currPosi = posi[i];
            }
            if(balls == maxBalls)
                return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 1;
        int h = position[n -1] - position[0];
        
        int ans = 0;
        
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(isDistanceValid(mid, position, m))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        return ans;
    }
};