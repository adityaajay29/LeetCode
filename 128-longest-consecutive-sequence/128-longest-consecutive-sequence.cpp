class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        
        for(int x : nums)
            set.insert(x);
        
        int ans = 0;
        
        for(int x : set)
        {
            if(set.find(x - 1) == set.end())
            {
                int count = 1;
                int curr = x;
                while(set.find(x + 1) != set.end())
                {
                    count++;
                    x++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};