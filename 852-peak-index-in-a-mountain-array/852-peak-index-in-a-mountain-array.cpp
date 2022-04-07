class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // priority_queue<pair<int,int> >pq;
        // for(int i=0;i<arr.size();i++)
        // {
        //     pq.push({arr[i],i});
        // }
        // return pq.top().second;
        
        // for(int i=1;i<arr.size();i++)
        // {
        //     if(arr[i]<arr[i-1])
        //         return i-1;
        // }
        // return -1;
        
        int l=0;
        int h=arr.size()-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(arr[mid+1]>arr[mid])
                l=mid+1;
            else 
                h=mid;
        }
        return l;
    }
};