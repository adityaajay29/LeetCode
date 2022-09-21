class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0, n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(abs(nums[i]) % 2 == 0)
                sum += nums[i];
        }
        for(vector<int> &x : queries)
        {
            int val = x[0], ind = x[1];
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