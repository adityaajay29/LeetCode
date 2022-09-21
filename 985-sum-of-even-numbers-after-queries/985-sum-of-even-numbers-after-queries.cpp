class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0, n = nums.size();
        vector<int> ans;
        for(int x : nums)
        {
            if(abs(x % 2) == 0)
                sum += x;
        }
        for(vector<int> &v : queries)
        {
            int val = v[0], ind = v[1];
            int prev = nums[ind];
            nums[ind] += val;
            if(abs(prev) % 2 == 0)
                sum -= prev;
            if(abs(nums[ind]) % 2 == 0)
                sum += nums[ind];
            ans.push_back(sum);
        }
        return ans;
    }
};