class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        unordered_set<int> s;
        for(int x : nums)
            s.insert(x);
        int count = 1;
        int ans = 1;
        for(int x : nums)
        {
            if(s.find(x - 1) != s.end())
                continue;
            int temp = x;
            while(s.find(temp + 1) != s.end())
            {
                count++;
                temp++;
            }
            ans = max(ans, count);
            count = 1;
        }
        return ans;
    }
};