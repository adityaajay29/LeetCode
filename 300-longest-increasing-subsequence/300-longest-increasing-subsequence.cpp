class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for(int i = n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int notTake = prev[j + 1];
                int take = 0;
                if(j == -1 || nums[i] > nums[j])
                    take = 1 + prev[i + 1];
                curr[j + 1] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[-1 + 1];
    }
};