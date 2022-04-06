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
//             if mid is bad version, check if its previous version is bad or not
//             if the previous version is bad, then decrement high
//             else, simply return mid, as it is the first bad version
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