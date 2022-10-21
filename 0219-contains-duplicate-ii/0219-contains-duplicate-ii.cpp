class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(auto &x : mp)
        {
            if(x.second.size() >= 2)
            {
                vector<int> v = x.second;
                int i = 0;
                while(i + 1 < v.size())
                {
                    if(abs(v[i + 1] - v[i]) <= k)
                        return true;
                    
                    i++;
                }
            }
        }
        return false;
    }
};