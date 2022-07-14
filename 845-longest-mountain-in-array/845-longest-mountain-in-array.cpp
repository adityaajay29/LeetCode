class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> up(n, 0);
        vector<int>down(n, 0);
        int ans = 0;
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i + 1] < arr[i])
                down[i] = 1 + down[i + 1];
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i] > arr[i - 1])
                up[i] = 1 + up[i - 1];
            if(up[i] && down[i])
                ans = max(ans, up[i] + down[i] + 1);
        }
        return ans;
    }
};