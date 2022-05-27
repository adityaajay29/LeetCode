class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int x : nums)
        {
            mp[x]++;
        }
        for(pair<int, int> x : mp)
        {
            if(x.second > n/3)
                ans.push_back(x.first);
        }
        return ans;
    }
};