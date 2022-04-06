// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int h=n;
        if(isBadVersion(l))
            return 1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            bool res=isBadVersion(mid);
            if(res)
            {
                if(!isBadVersion(mid-1))
                    return mid;
                else
                    h=mid-1;
            }
            else
                l=mid+1;
        }
        return -1;
    }
};