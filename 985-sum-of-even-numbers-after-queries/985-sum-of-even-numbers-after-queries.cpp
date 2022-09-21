class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0, n = nums.size(), m = queries.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[i] = nums[i];
            if(abs(nums[i]) % 2 == 0)
                sum += nums[i];
        }
        for(vector<int> &x : queries)
        {
            int val = x[0], ind = x[1];
            int prev = mp[ind];
            mp[ind] += val;
            if(abs(prev) % 2 == 0)
                sum -= prev;
            if(abs(mp[ind]) % 2 == 0)
                sum += mp[ind];
            ans.push_back(sum);
        }
        return ans;
    }
};