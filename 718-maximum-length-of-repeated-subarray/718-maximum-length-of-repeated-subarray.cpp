class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(nums1 == nums2)
            return n1;
        
        if(n1 < n2)
            return findLength(nums2, nums1);
        
        vector<int> prev(n2 + 1);
        vector<int> curr(n2 + 1);
        int ans = 0;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(nums1[i - 1] == nums2[j - 1])
                {
                    prev[j] = 1 + curr[j - 1];
                }
                else
                {
                    prev[j] = 0;
                }
                ans = max(ans, prev[j]);
            }
            curr = prev;
        }
        return ans;
    }
};
