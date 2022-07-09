class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int twoPrev = 0;
        int prev = nums[0];
        
        for(int i=2;i<=n;i++)
        {
            int take = nums[i - 1] + twoPrev;
            int notTake = 0 + prev;
            int curr = max(take, notTake);
            twoPrev = prev;
            prev = curr;
        }
        
        return prev;
    }
};