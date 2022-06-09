class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        vector<int> arr;
        int l1 = 0;
        int l2 = 0;
        while(l1 < n1 && l2 < n2)
        {
            if(nums1[l1] <= nums2[l2])
            {
                arr.push_back(nums1[l1++]);
            }
            else 
                arr.push_back(nums2[l2++]);
        }
        while(l1 < n1)
            arr.push_back(nums1[l1++]);
        while(l2 < n2)
            arr.push_back(nums2[l2++]);
        if((n) % 2)
            return (double)arr[n/2];
        else
            return (arr[n/2] + arr[n/2 - 1])/2.0;
    }
};