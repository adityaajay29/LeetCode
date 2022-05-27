class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        for(auto x : mp)
            if(x.second > (n/2))
                return x.first;
        return -1;
    }
};