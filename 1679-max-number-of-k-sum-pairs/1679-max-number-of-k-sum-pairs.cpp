class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans=0;
        for(int n1:nums)
        {
            int n2=k-n1;
            if(mp[n1]>0)
            {
                mp[n1]--;
                ans++;
            }
            else 
                mp[n2]++;
        }
        return ans;
    }
};