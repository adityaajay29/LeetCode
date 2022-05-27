class Solution {
public:
    
    int merge(vector<int> &nums, int l, int h, int mid)
    {
        int count = 0;
        int j = mid+1;
        for(int i=l;i<=mid;i++)
        {
            while(j<=h && nums[i] > 2*(long long)nums[j])
            {
                j++;
            }
            count += (j - (mid+1));
        }
        vector<int> temp;
        int i = l;
        int k = mid +1;
        while(i<=mid && k<=h)
        {
            if(nums[i] <= nums[k])
            {
                temp.push_back(nums[i++]);
            }
            else
                temp.push_back(nums[k++]);
        }
        while(i <= mid)
        {
            temp.push_back(nums[i++]);
        }
        while(k <= h)
        {
            temp.push_back(nums[k++]);
        }
        for(int i=l;i<=h;i++)
        {
            nums[i] = temp[i-l];
        }
        return count;
    }
    
    int sort(vector<int> &nums, int l, int h)
    {
//         single ele will give 0 pair
        if(l >= h)
            return 0;
        int mid = l + (h-l)/2;
        int ans = sort(nums, l, mid);
        ans += sort(nums, mid+1, h);
        ans += merge(nums, l, h, mid);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        return sort(nums, 0, nums.size()-1);
    }
};