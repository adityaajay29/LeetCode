class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums)
            s.insert(x);
        int count = 1;
        int ans = 0;
        for(int x : nums)
        {
            if(s.find(x - 1) == s.end())
            {
                int temp = x;
                int count = 1;
                while(s.find(temp + 1) != s.end())
                {
                    count++;
                    temp++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};