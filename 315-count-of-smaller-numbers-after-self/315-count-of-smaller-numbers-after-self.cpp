class Solution {
public:
    void merge(vector<pair<int, int>> &v, vector<int> &ans, int l, int mid, int h)
    {
        vector<pair<int, int>> temp(h - l + 1);
        
        int i = l;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid && j <= h)
        {
            if(v[i].first <= v[j].first)
            {
                temp[k++] = v[j++];
            }
            else
            {
                ans[v[i].second] += h - j + 1;
                temp[k++] = v[i++];
            }
        }
        while (i <= mid) 
        {
            temp[k++] = v[i++];
        }
        while (j <= h) 
        {
            temp[k++] = v[j++];
        }
        for(int i = l; i <= h; i++)
            v[i] = temp[i - l];
    }
    
    void mergeSort(vector<pair<int, int>> &v, vector<int> &ans, int l, int h)
    {
        if(l >= h)
            return;
        
        int mid = l + (h - l) / 2;
        mergeSort(v, ans, l, mid);
        mergeSort(v, ans, mid + 1, h);
        merge(v, ans, l, mid, h);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i], i});
        }
        vector<int> ans(n, 0);
        mergeSort(v, ans, 0, n - 1);
        return ans;
    }
};