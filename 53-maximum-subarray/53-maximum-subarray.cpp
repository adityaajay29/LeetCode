class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int curr = 0;
        for(int x : nums)
        {
            curr += x;
            res = max(res, curr);
            if(curr < 0)
                curr = 0;
        }
        return res;
    }
};