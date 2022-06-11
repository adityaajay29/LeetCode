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
        
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(mp.find(sum - target) != mp.end())
            {
                ans = max(ans, i - mp[sum - target]);
            }
            mp[sum] = i;
        }
        return (ans == -1 ? -1 : n - ans);
    }
};