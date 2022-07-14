class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int up = 0;
        int down = 0;
        int ans = 0;
        
        for(int i=1;i<n;i++)
        {
            if(down != 0 && arr[i] > arr[i - 1] || arr[i] == arr[i - 1])
            {
                up = 0;
                down = 0;
            }
            up += (arr[i] > arr[i - 1]);
            down += (arr[i - 1] > arr[i]);
            if(up && down)
                ans = max(ans, up + down + 1);
        }
        return ans;
    }
};