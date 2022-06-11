class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for(int it : nums)
            totalSum += it;
        
        int target = totalSum - x;
        int n =  nums.size();
        
        if(target == 0)
            return n;
        
        if(target < 0)
            return -1;
        
        int sum = 0;
        int ans = -1;
        
        int l = 0;
        int h = 0;
        
        while(l < n && h <= n)
        {
            if(sum < target)
                sum += nums[h++];
            else
                sum -= nums[l++];
            if(sum == target)
                ans = max(ans, h - l);
        }
        return (ans == -1 ? -1 : n - ans);
    }
};