class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            for(auto x:mp)
            {
                if(x.second==target-nums[i])
                {
                    ans.push_back(i);
                    ans.push_back(x.first);
                    return ans;
                }
            }
            mp[i]=nums[i];
        }
        return {};
    }
};