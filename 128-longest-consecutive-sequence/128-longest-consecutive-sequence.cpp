class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        int count = 1;
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] != nums[i-1])
            {
                if(nums[i] - nums[i-1] == 1)
                    count++;
                else 
                {
                    count = 1;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};