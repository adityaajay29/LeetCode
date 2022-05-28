class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        int count = 1;
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        set<int> s;
        
        for(int x : nums)
        {
            s.insert(x);
        }
        vector<int> temp;
        for(auto x : s)
        {
            temp.push_back(x);
        }
        for(int i=0;i<temp.size()-1;i++)
        {
            if(temp[i+1] - temp[i] == 1)
                count++;
            else 
                count = 1;
            ans = max(ans, count);
        }
        return ans;
    }
};