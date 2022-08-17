class Solution {
public:
    bool isPossible(vector<int> &arr, int maxForce, int maxBalls)
    {
        int posi = arr[0];
        int balls = 1;
        for(int i=1;i<arr.size();i++)
        {
            int force = arr[i] - posi;
            if(force >= maxForce)
            {
                balls++;
                posi = arr[i];
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
        int h = position[n - 1] - position[0];
        int ans = 0;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(isPossible(position, mid, m))
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