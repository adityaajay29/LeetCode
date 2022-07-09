class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        
        for(int i = 1;i<n;i++)
        {
//             pop the invalid index
            if(dq.front() < i - k)
                dq.pop_front();
//             pust the max value in the dp along with curr value
            dp[i] = nums[i] + dp[dq.front()];
//             pop all the smaller ele to maintain the decreasing order from left to right in deque
            while(!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();
//             push the curr index
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};