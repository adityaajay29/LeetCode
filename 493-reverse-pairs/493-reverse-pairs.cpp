class Solution {
public:
    int merge(vector<int> &nums, int l, int mid, int h)
    {
        int res = 0;
        int j = mid + 1;
        for(int i=l;i<=mid;i++)
        {
            while(j <= h && (long long)nums[i] > (2 * (long long)nums[j]))
                j++;
            res += (j - (mid + 1));
        }
        vector<int> temp;
        int i = l, k = mid + 1;
        while(i <= mid && k <= h)
        {
            if(nums[i] <= nums[k])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[k++]);
        }
        while(i <= mid)
            temp.push_back(nums[i++]);
        while(k <= h)
            temp.push_back(nums[k++]);
        for(int i = l;i<=h;i++)
        {
            nums[i] = temp[i - l];
        }
        return res;
    }
    
    int mergeSort(vector<int> &nums, int l, int h)
    {
        if(l >= h)
            return 0;
        
        int mid = l + (h - l) / 2;
        int ans = mergeSort(nums, l, mid);
        ans += mergeSort(nums, mid + 1, h);
        ans += merge(nums, l, mid, h);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        return mergeSort(nums, l, h);
    }
};