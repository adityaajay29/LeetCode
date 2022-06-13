class Solution {
public:
    bool isValid(int maxLimit, vector<int> &cookies, int maxChild)
    {
        do
        {
            int child = 1;
            int currLimit = 0;
            int n = cookies.size();
            for(int i=0;i<n;i++)
            {
                if(currLimit + cookies[i] > maxLimit)
                {
                    child++;
                    currLimit = cookies[i];
                    
                    if(currLimit > maxLimit)
                        return false;
                }
                else
                    currLimit += cookies[i];
            }
            if(child <= maxChild)
                return true;
        }while(next_permutation(cookies.begin(), cookies.end()));
        return false;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(), cookies.end());
        int n = cookies.size();
        int l = cookies[n-1];
        int h = 0;
        int ans = 0;
        for(int x : cookies)
            h += x;
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(isValid(mid, cookies, k))
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